/*
 * Copyright (c) 2004-2005 The Trustees of Indiana University and Indiana
 *                         University Research and Technology
 *                         Corporation.  All rights reserved.
 * Copyright (c) 2004-2006 The University of Tennessee and The University
 *                         of Tennessee Research Foundation.  All rights
 *                         reserved.
 * Copyright (c) 2004-2005 High Performance Computing Center Stuttgart, 
 *                         University of Stuttgart.  All rights reserved.
 * Copyright (c) 2004-2005 The Regents of the University of California.
 *                         All rights reserved.
 * Copyright (c) 2008-2011 University of Houston. All rights reserved.
 * $COPYRIGHT$
 * 
 * Additional copyrights may follow
 * 
 * $HEADER$
 */

#ifndef MCA_FCOLL_TWO_PHASE_EXPORT_H
#define MCA_FCOLL_TWO_PHASE_EXPORT_H

#include "ompi_config.h"

#include "mpi.h"
#include "opal/mca/mca.h"
#include "ompi/mca/fcoll/fcoll.h"
#include "ompi/mca/fcoll/base/base.h"
#include "ompi/mca/io/ompio/io_ompio.h"

BEGIN_C_DECLS

/* Globally exported variables */

extern int mca_fcoll_two_phase_priority;
extern int mca_fcoll_two_phase_num_io_procs;
extern int mca_fcoll_two_phase_constant_cbs;
extern int mca_fcoll_two_phase_cycle_buffer_size;

OMPI_MODULE_DECLSPEC extern mca_fcoll_base_component_2_0_0_t mca_fcoll_two_phase_component;

/* API functions */

int mca_fcoll_two_phase_component_init_query(bool enable_progress_threads,
                                           bool enable_mpi_threads);
struct mca_fcoll_base_module_1_0_0_t *
mca_fcoll_two_phase_component_file_query (mca_io_ompio_file_t *fh, int *priority);

int mca_fcoll_two_phase_component_file_unquery (mca_io_ompio_file_t *file);

int mca_fcoll_two_phase_module_init (mca_io_ompio_file_t *file);
int mca_fcoll_two_phase_module_finalize (mca_io_ompio_file_t *file);

int mca_fcoll_two_phase_file_read_all (mca_io_ompio_file_t *fh, 
                                     void *buf, 
                                     int count,
                                     struct ompi_datatype_t *datatype, 
                                     ompi_status_public_t * status);

int mca_fcoll_two_phase_file_read_all_begin (mca_io_ompio_file_t *fh, 
                                           void *buf, 
                                           int count, 
                                           struct ompi_datatype_t *datatype);

int mca_fcoll_two_phase_file_read_all_end (mca_io_ompio_file_t *fh, 
                                         void *buf, 
                                         ompi_status_public_t * status);

int mca_fcoll_two_phase_file_write_all (mca_io_ompio_file_t *fh, 
                                      void *buf, 
                                      int count,
                                      struct ompi_datatype_t *datatype, 
                                      ompi_status_public_t * status);

int mca_fcoll_two_phase_file_write_all_begin (mca_io_ompio_file_t *fh, 
                                            void *buf, 
                                            int count, 
                                            struct ompi_datatype_t *datatype);

int mca_fcoll_two_phase_file_write_all_end (mca_io_ompio_file_t *fh, 
                                          void *buf, 
                                          ompi_status_public_t * status);

END_C_DECLS

#endif /* MCA_FCOLL_TWO_PHASE_EXPORT_H */