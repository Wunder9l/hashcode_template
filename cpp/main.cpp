#include "models.h"
#include "checker.h"
#include "annealing_simulator.h"
#include "constants.h"
#include "solver.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;


void DoAnnealing(TEnvironment& env, const string& debugFilename, const string& dumpFilename) {
    // IChecker checker = MakeChecker(env);

    const double startTemp = env.Constants.GetDouble(NKnownConstants::START_TEMPERATURE);
    const double endTemp = env.Constants.GetDouble(NKnownConstants::END_TEMPERATURE);
    // Create annealing simulator
    // IAnnealingSimulator myAnnealingSimulator (startTemp, env, checker);

    // Create annealing begin state
    // TAnnealingState startState;
    if (!dumpFilename.empty() && dumpFilename != "-") {
        // startState.RestoreFromFile(dumpFilename);
    }

    // auto annealing = Annealing<IAnnealingSimulator>(myAnnealingSimulator);
    const ui64 maxIterations = env.Constants.GetInt(NKnownConstants::ITERATIONS);


    // Create debug class for annealing logging
    //    DebugClass debug(maxIterations);
    //    std::function<void(uint64_t, const DeliverySimulatorState&, double, double)> callback =
    //            [&debug](uint64_t i, const DeliverySimulatorState& state, double energy, double temperature) {
    //                debug.AddLogEntry(i, state, energy, temperature);
    //            };

    cout << "Start of annealing simulation: T_start=" << startTemp << ", T_end=" << endTemp << ", maxIterations="
         << maxIterations << endl;
    // cout << "Start state (energy=" << deliverySimulator.EnergyCallback(startState) << "):" << endl;

    //    const auto&[state, res] = annealing.Run(startTemp, endTemp, startState, maxIterations, &callback);
    //    cout << "Result of annealing simulation: " << deliverySimulator.GetPoints(state) << ", energy=" << res << endl;

    //    debug.WriteToFile(debugFilename);
}

int main(int argc, char* argv[]) {
    TEnvironment env;
    ReadFromFile<TEnvironment>(argv[2], env, ReadEnvironment);

    if (!strcmp(argv[1], "solve")) {
        // format: solve [filename_with_env] [filename_to_write_results] [constants [{intConst name=value doubleConst name=value}]]

        if (argc > 4) {
            env.Constants.ParseConstants(argv + 4, argc - 4);
        }

        TSolver solver(env);
        TSolution solution = solver.Solve();

        TChecker checker(env);
        auto score = checker.CheckSolution(solution);
        cout << "Result of solving (" << argv[2] << ") is " << score << endl;
        WriteToFile<TSolution>(argv[3], solution, WriteSolution);
    } else if (!strcmp(argv[1], "eval")) {
        // format: eval [filename_with_env] [filename_with_results]

        TChecker checker(env);
        auto score = checker.CheckSolutionFromFile(argv[3]);
        cout << "Result of checking (" << argv[3] << ") is " << score << endl;
    } else if (!strcmp(argv[1], "annealing")) {
        // format: annealing [filename_with_env] [filename_to_write_results] [filename_with_dump (or -) if none] [constants [{intConst name=value doubleConst name=value}]]

        if (argc > 5) {
            env.Constants.ParseConstants(argv + 5, argc - 5);
        }
        DoAnnealing(env, argv[3], argv[4]);
    } else {
        cout << "Do not know what to do with  " << argv[1];
    }
}