# Jamba
This is a Jmaba project for parallel computing.

Technologies used : openmp, Python ctypes, boost and cpp
 
 This project is very simple when it comes to implementation but the processing it does is really super fast and resulets are impressive.

| Number Of Threads / Requests  | 1 Thread         | 2 Threads      | 4 Threads      | 8 Threads      | 16 Threads       | 32 Threads     | 64 Threads |
| :---------------------------: |:----------------:| :-------------:| :-------------:| :-------------:| :---------------:| :-------------:| :----------:|
| 100 Requests                  | 114 (1.14) 	   | 59.61 (0.59)   | 46.57 (0.46)   | 15.92 (0.15)   | 9.21 (0.09)      | 7.51 (0.075)   | 7.86 (0.078) |
| 1,000 Requests                 | 1149.31 (1.14)   | 578.47 (0.578) | 303.13 (0.303) | 150.38 (0.150) | 80.54 (0.080)    | 54.21 (0.054)  | 41.35 (0.041) |
| 10,000 Requests                | 11,298.4 (1.129) | 5712.5 (0.571) | 3050.8 (0.305) | 1516.4 (0.151) | 1626.42 (0.162)  | 1749.4 (0.174) | 1722.53 (0.1722) |
| 100,000 Requests  				| 111,777 (1.11)   | 56,783 (0.567) | 30,813 (0.308) | 15007 (0.150)  | 17,999.2 (0.179) | 18,575 (0.185) | 18,202.58 (0.182) |

Here 114(1.14) = "total time taken to execute all requests in milliseconds" (time per request in milliseconds)
