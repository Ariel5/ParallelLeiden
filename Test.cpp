#include "ParallelLeiden.hpp"
#include <networkit/io/METISGraphReader.hpp>
#include <fstream>
#include <networkit/io/SNAPGraphReader.hpp>


int main() {
    Graph g = SNAPGraphReader().read("/home/ariel/prog/Thesis-Graph-Data/twitch.csv");
    ParallelLeiden pl(g);
    Aux::setNumberOfThreads(8);
    auto tmr = Aux::Timer();
    tmr.start();
    pl.run();
    cout << "Elapsed time (s): " << tmr.elapsedMilliseconds() / 1000.0 << " | Modularity Quality: " << Modularity().getQuality(pl.getPartition(), g) << endl;
    return 0;
}

