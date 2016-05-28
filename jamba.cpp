#include <omp.h>
#include <stdio.h>
#include <sys/time.h>
#include <cstdlib> //Contains the random functions we need.
#include <boost/chrono.hpp>

using namespace boost::chrono;


class Jamba{

  // struct for creating requests
  struct request
    {
      int mongo;
      int bannana;
      int apple;
      int berry;
      int kale;
      int peach;
      int strawberry;
      int mellon; 
    };


    public:
        void processRequestMainMethod(int numOfWorkers, int numOfRequests){
            std::cout << "Process Started...!" << std::endl;

            processRequests(numOfWorkers, numOfRequests);            

            std::cout << "Process Ended...!" << std::endl;
        }

    void processRequests(int numOfWorkers, int numOfRequests){

      if(numOfWorkers == 0){
        numOfWorkers = 4;
      }
      if(numOfRequests == 0){
        numOfRequests = 1000;
      }

      int number_of_jambas = numOfRequests;
       request JambaRequest[number_of_jambas];
       /*{{1,0,0,0,0,0,0,0},
        {0,1,0,1,0,0,0,0}, {1,0,0,1,0,0,1,0},{1,0,1,0,1,0,0,0},
           {0,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,0},{1,0,1,0,1,0,0,0 }, {1,0,1,0,0,0,0,1},{1,0,1,1,0,0,0,0},{1,1,1,0,0,0,0,0}
          };*/
          
          for(int i=0;i< number_of_jambas;i++){
          
            JambaRequest[i].mongo =rand() % 2; 
            JambaRequest[i].bannana =rand() % 2; 
            JambaRequest[i].apple =rand() % 2; 
            JambaRequest[i].berry =rand() % 2; 
            JambaRequest[i].kale =rand() % 2; 
            JambaRequest[i].peach =rand() % 2;
            JambaRequest[i].strawberry =rand() % 2;
            JambaRequest[i].mellon =rand() % 2;    
        }
        
       omp_set_num_threads(numOfWorkers);
       auto dt_s = high_resolution_clock::now();
       int threads = 0;


       // Section where we are using blenders for serving request parallelly.
        #pragma omp parallel for ordered schedule(dynamic)
        for(int i=0;i<number_of_jambas;i++){
                  if(JambaRequest[i].mongo ==1 ) printf ("  add mongo");
                  if(JambaRequest[i].bannana ==1) printf("  add bannana");
                  if(JambaRequest[i].apple ==1 ) printf ("  add apple");
                  if(JambaRequest[i].berry ==1 ) printf ("  add berry");
                  if(JambaRequest[i].kale ==1 ) printf  ("  add kale");
                  if(JambaRequest[i].peach ==1 ) printf ("  add peach");
                  if(JambaRequest[i].strawberry ==1 ) printf(" add strawberry");
                  if(JambaRequest[i].mellon ==1 ) printf(" add mellon");
           printf(" Request %d Done ! \n", (i+1));
           int ID = omp_get_thread_num();
           printf("%d", ID);

          if(threads < omp_get_num_threads()){
            threads = omp_get_num_threads();
          }

          // for check out
           usleep(1000);
        }

          //int threads = omp_get_num_threads();
          printf("\nMaximum threads used for this request : %d",threads);      
          auto dt = duration_cast<nanoseconds> (high_resolution_clock::now() - dt_s);
          std::cout << "\nTime taken to fulfill requests in nanoseconds = " << dt.count() << " ns" << "\n";
          std::cout << "\nTime per request = " << (dt.count()/(numOfRequests)) << " ns" << "\n";
          //std::cout << "agreement: " << std::setprecision(18) << (ref - val) << "\n";
    }
};

extern "C" {
    Jamba* Jamba_new(){ return new Jamba(); }
    void Jamba_processRequestMainMethod(Jamba* jamba, int numOfWorkers, int numOfRequests){ jamba->processRequestMainMethod(numOfWorkers, numOfRequests); }
}





