/*
 * iBMQ_common.h
 *
 *  Created on: Feb 28, 2012
 *      Author: hoblitz
 */

#ifndef IBMQ_COMMON_H_
#define IBMQ_COMMON_H_

#include <R.h>
#include <Rmath.h>
#include "RngStream.h"
#include "norm_gamma_generation.h"
#include "sparse.h"
#include "ARS.h"
#include <float.h>

#include <Rconfig.h>
// conditional omp support
#ifdef SUPPORT_OPENMP
#include <omp.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <Rversion.h>

#include <gsl/gsl_math.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_statistics_double.h>
#include <gsl/gsl_sf.h>
#include <gsl/gsl_check_range.h>

double expit(const double x);
double log_from_logit(const double x);
double log1m_from_logit(const double x);
double logit(const double x);
double lc_AB(const double x, const double *argvec);
double lcp_AB(const double x, const double *argvec);

void store_prob_include(const int n_iter, const int n_snps,
		const int n_genes, int** ProbSum, double* outProbs);

void update_prob_include(const int n_snps, const int n_genes,
		int** Gamma, int** ProbSum);

int update_pos_j(double* P, double* A, double* B, double** W_Logit,
		int** W_Ind, int** Gamma, int j, double* a_0, double* b_0,
		double* lambda_a, double* lambda_b, int* n_genes, RngStream rng,
		int nmax, double *xA, double *xB, ARS_workspace *workspace);

void set_prior(double* lambda_a, double* lambda_b, double* a_0, double* b_0,
		double *tau_0, double* expr_means, double* expr_vars,
		double* alpha2_beta, gsl_matrix* X, gsl_matrix* Y, RngStream rng);

void initialize_parms(ptr_m_el *Beta, ptr_memPool ptr_pool, int** Gamma, double** W_Logit, int** W_Ind, int** ProbSum, double **xA, double **xB,
		double* A, double* B, double* C, double* P, double* Mu, double* Sig2,
		double* expr_means, double* expr_vars, double* alpha2_beta,
		double* lambda_a, double* a_0, double* lambda_b, double* b_0, double* tau_0,
		int* n_snps, int* n_genes, int* n_indivs, int* nmax, RngStream rng);

#endif /* IBMQ_COMMON_H_ */


