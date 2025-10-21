#include<stdio.h>
#include<stdlib.h>


double run_plc(char filename[],int rank1)
{

  char command[100];
  double A[14];
  
  A[0] = 0.2035919e03;  // A^{PS}_{100}
  A[1] = 0.7221782e02;  // A^{PS}_{143}
  A[2] = 0.6017222e02;  // A^{PS}_{217}
  A[3] = 0.3253835e01;  // A^{CIB}_{143}
  A[4] = 0.5231600e02;  // A^{CIB}_{217}
  A[5] = 0.4644192e01;  // A^{tSZ}_{143}
  A[6] = 0.8141186e00;  // r^{PS}_{143\times217}
  A[7] = 0.1000000e01;  // r^{CIB}_{143\times217}
  A[8] = 0.6563661e00;  // \gamma^{CIB}
  A[9] = 0.1000592e01;  // c_{100}
  A[10]= 0.9973067e00;  // c_{217}
  A[11]= 0.0000000e00;  // \xi^{tSZ-CIB}
  A[12]= 0.1139657e01;  // A^{kSZ}
  A[13]= 0.3847442e00;  //\beta^1_1

  FILE *readfile,*TTwrite,*TEBwrite;
  char writeTT[20],writeTEB[20];

  readfile = fopen(filename,"r");

  printf("Hi this is a test project\n");
 
  // Write in TT file
   
  sprintf(writeTT,"TT_%d.d",rank1);
  TTwrite = fopen(writeTT,"w");

  sprintf(writeTEB,"TEB_%d.d",rank1);
  TEBwrite = fopen(writeTEB,"w");
	
  int i,temp;
  double TTd,TEd,EEd,BBd,Td;
  double TTtemp[35]={0.0},TEtemp[35]={0.0},EEtemp[35]={0.0},BBtemp[35]={0.0};

  for(i=0;i<=1;i++)
  {
    fprintf(TTwrite,"0.000\n");	
//    fprintf(TEBwrite,"0.000 0.000 0.000 0.000\n");    
    }	

  printf("\n\n\n%s\n\n\n",filename);  
for(i=2;i<=32;i++)
  {
     fscanf(readfile,"%d %lf %lf %lf %lf",&temp,&TTd,&EEd,&BBd,&TEd);
     fprintf(TTwrite,"%e\n",TTd/(double)(temp*(temp+1)/2)*3.14159256);
     //fprintf(TTwrite,"%e\n",TTd/(double)(temp*(temp+1)/2)*3.14/(2.73e6*2.73e6));
     TTtemp[i] = TTd/(double)(temp*(temp+1)/2)*3.14159256;
     TEtemp[i] = TEd/(double)(temp*(temp+1)/2)*3.14159256;
     EEtemp[i] = EEd/(double)(temp*(temp+1)/2)*3.14159256;
     BBtemp[i] = BBd/(double)(temp*(temp+1)/2)*3.14159256;
     //fprintf(TEBwrite,"%e %e %e %e\n",TTd,EEd,BBd,TEd);
     }

  for(i=0;i<=32;i++)
     fprintf(TEBwrite,"%e\n",TTtemp[i]);
  for(i=0;i<=32;i++)
     fprintf(TEBwrite,"%e\n",EEtemp[i]);
  for(i=0;i<=32;i++)
     fprintf(TEBwrite,"%e\n",BBtemp[i]);
  for(i=0;i<=32;i++)
     fprintf(TEBwrite,"%e\n",TEtemp[i]);

  for(i=33;i<=2500;i++)
  {
     fscanf(readfile,"%d %lf %lf %lf %lf",&temp,&TTd,&TEd,&EEd,&BBd);
     fprintf(TTwrite,"%e\n",TTd/(double)(temp*(temp+1)/2)*3.14159256);
     }

  for(i=0;i<14;i++)
  {
     fprintf(TTwrite,"%e\n",A[i]);
     }	

  fclose(readfile);
  fclose(TTwrite);
  fclose(TEBwrite);

  sprintf(command,"rm %s",filename);
  //system(command);
  
// printf("\nStuck here");

  sprintf(command,"/data1/student/csantanud/plc-1.0/buildir/clik_example_C_1 /data1/student/csantanud/data/clik/CAMspec_v6.2TN_2013_02_26_dist.clik/ %s",writeTT);
  system(command);

// printf("\nStuck here 2");

  //exit(1);
  sprintf(command,"%s.like",writeTT);
  FILE *fpchk;
l1k:
  fpchk = fopen(command,"r");
  if(fpchk == NULL)
  {
//    sleep(1);
    printf("HIIIIII\n");
    goto l1k;
  }
  double result1;
  fscanf(fpchk,"%lf",&result1);
  fclose(fpchk);

  sprintf(command,"/data1/student/csantanud/plc-1.0/buildir/clik_example_C_1 /data1/student/csantanud/data/clik/commander_v4.1_lm49.clik/ %s",writeTT);
  system(command);

  sprintf(command,"/data1/student/csantanud/plc-1.0/buildir/clik_example_C_1 /data1/student/csantanud/data/clik/lowlike_v222.clik/ %s",writeTEB);
  system(command);

  sprintf(command,"%s.like",writeTT); 
//  FILE *fpchk;
l1i:
  fpchk = fopen(command,"r");
  if(fpchk == NULL)
  {
//    sleep(1);
    printf("HIIIIII\n");
    goto l1i;
  }
  double result11;
  fscanf(fpchk,"%lf",&result11);
  fclose(fpchk);


  sprintf(command,"%s.like",writeTEB); 
l1j:
  fpchk = fopen(command,"r");
  if(fpchk == NULL)
  {
//    sleep(1);
    printf("HIIIIII\n");
    goto l1j;
  }
  double result2;
  fscanf(fpchk,"%lf",&result2);
  fclose(fpchk);



  return -2*(result1+result11+result2);

}


