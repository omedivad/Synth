/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 * Generated by MATLAB(R) 9.1 and the Signal Processing Toolbox 7.3.
 * Generated on: 07-Jan-2018 17:30:49
 */

/*
 * Discrete-Time FIR Filter (real)
 * -------------------------------
 * Filter Structure  : Direct-Form FIR
 * Filter Length     : 301
 * Stable            : Yes
 * Linear Phase      : Yes (Type 1)
 */

/* General type conversion for MATLAB generated C-code  */
// #include "tmwtypes.h"
/* 
 * Expected path to tmwtypes.h 
 * C:\Program Files\MATLAB\R2016b\extern\include\tmwtypes.h 
 */
const int HBL = 301;
const double HB[301] = {
  -0.0008246458776206, 0.001641604031207,0.0008550408983013,0.0005482023984665,
  0.0004114720648184,0.0003230016073843,0.0002364536918493,0.0001369003719207,
  2.312998930412e-05,-9.942457382899e-05,-0.0002219235497802,-0.0003342069019932,
  -0.0004257684393651,-0.0004869555079393,-0.0005102868570657,-0.0004908931171334,
  -0.0004273877229102,-0.0003222490945327,-0.0001816495906656,-1.551602473755e-05,
  0.0001635907015708,0.0003407145211178,0.0005003897913512,0.0006274451270798,
  0.0007087516413223,0.0007341537476708,0.0006977863211308, 0.000598877278027,
  0.0004420474068422,0.0002372158712076,-9.211057199958e-07,-0.0002538041398159,
  -0.000500403327892,-0.0007190417368033,-0.0008891838580165,-0.0009931859635069,
  -0.001018148642981,-0.000957166226098,-0.0008106073985264,-0.0005859696390017,
  -0.0002981412163309,3.184906072359e-05,0.0003779116822874,0.0007112456527435,
   0.001002549637688, 0.001224401139691, 0.001353877925824, 0.001374716294959,
   0.001279225774127, 0.001069234742126,0.0007563888103894,0.0003620115464088,
  -8.443873380321e-05,-0.0005477211570663,-0.0009887119484822,-0.001369273848581,
  -0.001651893109185,-0.001810664878841,-0.001820476669356,-0.001678418648539,
  -0.001384640702782,-0.0009570415780742,-0.0004275302074086,0.0001662747384787,
  0.0007773616742122, 0.001352574714764, 0.001841428724769,  0.00219936070355,
    0.00238869059767, 0.002383677398999, 0.002175307059018, 0.001771703782475,
   0.001197501855848, 0.000492383252263,-0.0002907936880289,-0.001088740676791,
  -0.001834067467084,-0.002460425445454,-0.002909155651935,-0.003133335366865,
  -0.003102795546469,-0.002807092197471,-0.002257793123399,-0.001488633161156,
  -0.0005537923593799,0.0004756940001482, 0.001517235635651, 0.002483079962163,
   0.003287382488023, 0.003853647874122,  0.00412164255424, 0.004053236953399,
   0.003636727114657, 0.002889035873824, 0.001856193191716,0.0006105785086564,
  -0.0007534986740104,-0.002127017302438,-0.003394120269306,-0.004441684302951,
  -0.005168941346227,-0.005496646881621,-0.005374812446621,-0.004788260623399,
  -0.003760049229786,-0.002351723154116,-0.0006601956304808, 0.001188312410087,
   0.003047033004529, 0.004759517928498, 0.006171847394042,  0.00714641624047,
   0.007572581990408, 0.007379575806222, 0.006541793401834,  0.00508803643412,
   0.003097454195844,0.0007007431769807,-0.001928927001764,-0.004587960830506,
  -0.007054395576385,-0.009105999842041, -0.01053818001991,  -0.0111801642312,
   -0.01091170110021,-0.009677092080618,-0.007493241692199,-0.004453982719662,
  -0.0007308766055182, 0.003434787012253, 0.007744424249142,  0.01185718002663,
    0.01541227345696,  0.01805087148083,  0.01944229363968,   0.0193059248633,
    0.01743387941052,  0.01370842157095, 0.008115273089664,0.0007497150513476,
  -0.008183880534901, -0.01837905223715, -0.02944105407563, -0.04090689194456,
   -0.05227025894619, -0.06300967847692, -0.07261790033153, -0.08063128912945,
   -0.08665721511083, -0.09039723802505,    0.908334928641, -0.09039723802505,
   -0.08665721511083, -0.08063128912945, -0.07261790033153, -0.06300967847692,
   -0.05227025894619, -0.04090689194456, -0.02944105407563, -0.01837905223715,
  -0.008183880534901,0.0007497150513476, 0.008115273089664,  0.01370842157095,
    0.01743387941052,   0.0193059248633,  0.01944229363968,  0.01805087148083,
    0.01541227345696,  0.01185718002663, 0.007744424249142, 0.003434787012253,
  -0.0007308766055182,-0.004453982719662,-0.007493241692199,-0.009677092080618,
   -0.01091170110021,  -0.0111801642312, -0.01053818001991,-0.009105999842041,
  -0.007054395576385,-0.004587960830506,-0.001928927001764,0.0007007431769807,
   0.003097454195844,  0.00508803643412, 0.006541793401834, 0.007379575806222,
   0.007572581990408,  0.00714641624047, 0.006171847394042, 0.004759517928498,
   0.003047033004529, 0.001188312410087,-0.0006601956304808,-0.002351723154116,
  -0.003760049229786,-0.004788260623399,-0.005374812446621,-0.005496646881621,
  -0.005168941346227,-0.004441684302951,-0.003394120269306,-0.002127017302438,
  -0.0007534986740104,0.0006105785086564, 0.001856193191716, 0.002889035873824,
   0.003636727114657, 0.004053236953399,  0.00412164255424, 0.003853647874122,
   0.003287382488023, 0.002483079962163, 0.001517235635651,0.0004756940001482,
  -0.0005537923593799,-0.001488633161156,-0.002257793123399,-0.002807092197471,
  -0.003102795546469,-0.003133335366865,-0.002909155651935,-0.002460425445454,
  -0.001834067467084,-0.001088740676791,-0.0002907936880289, 0.000492383252263,
   0.001197501855848, 0.001771703782475, 0.002175307059018, 0.002383677398999,
    0.00238869059767,  0.00219936070355, 0.001841428724769, 0.001352574714764,
  0.0007773616742122,0.0001662747384787,-0.0004275302074086,-0.0009570415780742,
  -0.001384640702782,-0.001678418648539,-0.001820476669356,-0.001810664878841,
  -0.001651893109185,-0.001369273848581,-0.0009887119484822,-0.0005477211570663,
  -8.443873380321e-05,0.0003620115464088,0.0007563888103894, 0.001069234742126,
   0.001279225774127, 0.001374716294959, 0.001353877925824, 0.001224401139691,
   0.001002549637688,0.0007112456527435,0.0003779116822874,3.184906072359e-05,
  -0.0002981412163309,-0.0005859696390017,-0.0008106073985264,-0.000957166226098,
  -0.001018148642981,-0.0009931859635069,-0.0008891838580165,-0.0007190417368033,
  -0.000500403327892,-0.0002538041398159,-9.211057199958e-07,0.0002372158712076,
  0.0004420474068422, 0.000598877278027,0.0006977863211308,0.0007341537476708,
  0.0007087516413223,0.0006274451270798,0.0005003897913512,0.0003407145211178,
  0.0001635907015708,-1.551602473755e-05,-0.0001816495906656,-0.0003222490945327,
  -0.0004273877229102,-0.0004908931171334,-0.0005102868570657,-0.0004869555079393,
  -0.0004257684393651,-0.0003342069019932,-0.0002219235497802,-9.942457382899e-05,
  2.312998930412e-05,0.0001369003719207,0.0002364536918493,0.0003230016073843,
  0.0004114720648184,0.0005482023984665,0.0008550408983013, 0.001641604031207,
  -0.0008246458776206
};
