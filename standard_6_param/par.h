#ifndef _PAR_H_
#define _PAR_H_

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int param(int mid,double task[])
{
  double As;
  As = exp(task[5]+2*task[3])*1.0e-10;
  char param[15],omegafile[15];
  sprintf(param,"param_%d.ini",mid);

  double Hub = task[2];
  double Omegam = task[0]/Hub/Hub;
  double Omegal = 1.0 - Omegam;
  double Omegar = 8.023e-5;

  double a,a1,a3,f21,f2,f1,f,H0oHa,agssd,aomega;


  FILE *fpwrite;
  fpwrite =fopen(param,"w+"); 
  fprintf(fpwrite,"output_root = test_%d\n",mid);
  fprintf(fpwrite,"get_scalar_cls = T\n");
  fprintf(fpwrite,"get_vector_cls = F\n");
  fprintf(fpwrite,"get_tensor_cls = F\n");
  fprintf(fpwrite,"get_transfer   = F\n");
  fprintf(fpwrite,"do_lensing     = T\n");
  fprintf(fpwrite,"do_nonlinear = 0\n");
  fprintf(fpwrite,"l_max_scalar      = 2700\n");
  fprintf(fpwrite,"l_max_tensor      = 1500\n");
  fprintf(fpwrite,"k_eta_max_tensor  = 5000\n");
  fprintf(fpwrite,"use_physical   = T\n");
  fprintf(fpwrite,"ombh2          = %e\n",task[1]);
  fprintf(fpwrite,"omch2          = %e\n",task[0]-task[1]);
  fprintf(fpwrite,"omnuh2         = 0\n");
  fprintf(fpwrite,"omk            = 0\n");
  fprintf(fpwrite,"hubble         = %e\n",100*task[2]);
  fprintf(fpwrite,"w              = -1.0\n");
  fprintf(fpwrite,"usew0wa = T\n");
  fprintf(fpwrite,"#if usew0wa = T, read in w_0, w_a \n");
  fprintf(fpwrite,"w0             = -1.0\n");
  fprintf(fpwrite,"wa             =  0.0\n");
  fprintf(fpwrite,"#if usew0wa = F, read (a,w) from the following user-supplied file\n");
  fprintf(fpwrite,"wafile = \n");
  fprintf(fpwrite,"#constant comoving sound speed of the dark energy (1=quintessence)\n");
  fprintf(fpwrite,"cs2_lam        =  1.0\n");
  fprintf(fpwrite,"temp_cmb           = 2.726\n");
  fprintf(fpwrite,"helium_fraction    = 0.24\n");
  fprintf(fpwrite,"massless_neutrinos = 3.046\n");
  fprintf(fpwrite,"massive_neutrinos  = 0\n");
  fprintf(fpwrite,"nu_mass_eigenstates = 1\n");
  fprintf(fpwrite,"nu_mass_degeneracies = 0  \n");
  fprintf(fpwrite,"nu_mass_fractions = 1\n");
  fprintf(fpwrite,"initial_power_num         = 1\n");
  fprintf(fpwrite,"pivot_scalar              = 0.05\n");
  fprintf(fpwrite,"pivot_tensor              = 0.002\n");
  fprintf(fpwrite,"scalar_amp(1)             = %e\n",As);
  fprintf(fpwrite,"scalar_spectral_index(1)  = %e\n",task[4]);
  fprintf(fpwrite,"scalar_nrun(1)            = 0\n");
  fprintf(fpwrite,"tensor_spectral_index(1)  = 0\n");
  fprintf(fpwrite,"initial_ratio(1)          = 1\n");
  fprintf(fpwrite,"reionization         = T\n");
  fprintf(fpwrite,"re_use_optical_depth = T\n");
  fprintf(fpwrite,"re_optical_depth     = %e\n",task[3]);
  fprintf(fpwrite,"re_redshift          = 11\n");
  fprintf(fpwrite,"re_delta_redshift    = 1.5\n");
  fprintf(fpwrite,"re_ionization_frac   = -1\n");
  fprintf(fpwrite,"RECFAST_fudge = 1.14\n");
  fprintf(fpwrite,"RECFAST_fudge_He = 0.86\n");
  fprintf(fpwrite,"RECFAST_Heswitch = 6\n");
  fprintf(fpwrite,"RECFAST_Hswitch  = T\n");
  fprintf(fpwrite,"initial_condition   = 1\n");
  fprintf(fpwrite,"initial_vector = -1 0 0 0 0\n");
  fprintf(fpwrite,"vector_mode = 0\n");
  fprintf(fpwrite,"COBE_normalize = F\n");
  fprintf(fpwrite,"CMB_outputscale = 7.4311e12\n");
  fprintf(fpwrite,"transfer_high_precision = F\n");
  fprintf(fpwrite,"transfer_kmax           = 2\n");
  fprintf(fpwrite,"transfer_k_per_logint   = 0\n");
  fprintf(fpwrite,"transfer_num_redshifts  = 1\n");
  fprintf(fpwrite,"transfer_interp_matterpower = T\n");
  fprintf(fpwrite,"transfer_redshift(1)    = 0\n");
  fprintf(fpwrite,"transfer_filename(1)    = transfer_out.dat\n");
  fprintf(fpwrite,"transfer_matterpower(1) = matterpower.dat\n");
  fprintf(fpwrite,"scalar_output_file = scalCls.dat\n");
  fprintf(fpwrite,"vector_output_file = vecCls.dat\n");
  fprintf(fpwrite,"tensor_output_file = tensCls.dat\n");
  fprintf(fpwrite,"total_output_file  = totCls.dat\n");
  fprintf(fpwrite,"lensed_output_file = lensedCls.dat\n");
  fprintf(fpwrite,"lensed_total_output_file  =lensedtotCls.dat\n");
  fprintf(fpwrite,"lens_potential_output_file = lenspotentialCls.dat\n");
  fprintf(fpwrite,"FITS_filename      = scalCls.fits\n");
  fprintf(fpwrite,"do_lensing_bispectrum = F\n");
  fprintf(fpwrite,"do_primordial_bispectrum = F\n");
  fprintf(fpwrite,"bispectrum_nfields = 1\n");
  fprintf(fpwrite,"bispectrum_slice_base_L = 0\n");
  fprintf(fpwrite,"bispectrum_ndelta=3\n");
  fprintf(fpwrite,"bispectrum_delta(1)=0\n");
  fprintf(fpwrite,"bispectrum_delta(2)=2\n");
  fprintf(fpwrite,"bispectrum_delta(3)=4\n");
  fprintf(fpwrite,"bispectrum_do_fisher= F\n");
  fprintf(fpwrite,"bispectrum_fisher_noise=0\n");
  fprintf(fpwrite,"bispectrum_fisher_noise_pol=0\n");
  fprintf(fpwrite,"bispectrum_fisher_fwhm_arcmin=7\n");
  fprintf(fpwrite,"bispectrum_full_output_file=\n");
  fprintf(fpwrite,"bispectrum_full_output_sparse=F\n");
  fprintf(fpwrite,"bispectrum_export_alpha_beta=F\n");
  fprintf(fpwrite,"feedback_level = 1\n");
  fprintf(fpwrite,"lensing_method = 1\n");
  fprintf(fpwrite,"accurate_BB = F\n");
  fprintf(fpwrite,"massive_nu_approx = 1\n");
  fprintf(fpwrite,"accurate_polarization   = T\n");
  fprintf(fpwrite,"accurate_reionization   = T\n");
  fprintf(fpwrite,"do_tensor_neutrinos     = T\n");
  fprintf(fpwrite,"do_late_rad_truncation   = T\n");
  fprintf(fpwrite,"number_of_threads       = 0\n");
  fprintf(fpwrite,"high_accuracy_default=F\n");
  fprintf(fpwrite,"accuracy_boost          = 1\n");
  fprintf(fpwrite,"l_accuracy_boost        = 1\n");
  fprintf(fpwrite,"l_sample_boost          = 1\n");
  fclose(fpwrite);
  
  char command[40];
  sprintf(command,"rm test_%d_*",mid);
  system(command);

  sprintf(command,"rm check_test_%d_*",mid);
  system(command);

  printf("\nTill now working fine :::::: %d",mid);

  sprintf(command,"rm cambdump.out");
  system(command);
  int commind = 3993;  
  sprintf(command,"camb/camb param_%d.ini >cambdump.out",mid);
  commind = system(command);

  sprintf(command,"check_test_%d_lensedCls.dat",mid);

  FILE *fpchk;
  int tempi = 0,tempiii;
  double tempfloat,tempfloat1;
  
  if(commind == 3993)
     return 0;

l1i:
  fpchk = fopen(command,"r");
  tempi++;

  printf("\nI am now printing new:: :: LL :: %s %d",command,tempi);

  if(fpchk == NULL)
  {
//   sleep(1);
   printf("\nInside filecheck :: **** ::");
    if(tempi<51)
       goto l1i;
    else 
       return 0; 
 }    

  fscanf(fpchk,"%d",&tempiii);

  if(tempiii == 0)
  {
     tempi = 513;
     fclose(fpchk);
     printf("\nTill now working fine 2 %d %d 0 check = %d",mid,tempi,tempiii);
     return 0;
     }

  fclose(fpchk);

  sprintf(command,"test_%d_lensedCls.dat",mid);
  tempiii = 0;
l2i:
  fpchk = fopen(command,"r+");
  tempiii++;
  if(fpchk == NULL)
  {
//  sleep(1);
    if(tempiii<51)
       goto l2i;
  }
  fscanf(fpchk,"%d %lf %lf %lf",&tempiii,&tempfloat,&tempfloat1,&tempfloat1);
  

  if(isnan(tempfloat))
  {
     tempi = 53;
     }
  fclose(fpchk);
  printf("\nTill now working fine 4 %d %d %d",mid,tempi,tempiii);

  if(tempi>50)
    return 0;
  else
    return 1; 

}

#endif
