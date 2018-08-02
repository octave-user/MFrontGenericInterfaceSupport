/*!
 * \file   BehaviourDataTest-c.c
 * \brief    
 * \author Thomas Helfer
 * \date   02/08/2018
 * \copyright (C) Copyright Thomas Helfer 2018.
 * Use, modification and distribution are subject
 * to one of the following licences:
 * - GNU Lesser General Public License (LGPL), Version 3.0. (See accompanying
 *   file LGPL-3.0.txt)
 * - CECILL-C,  Version 1.0 (See accompanying files
 *   CeCILL-C_V1-en.txt and CeCILL-C_V1-fr.txt).
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MGIS/Behaviour/BehaviourData.h"

int test_status = EXIT_SUCCESS;

static void check_status(const mgis_status s) {
  if (s.exit_status != MGIS_SUCCESS) {
    fprintf(stderr, "invalid function call: %s\n", s.msg);
    exit(EXIT_FAILURE);
  }
}  // end of check_status

static int check(const int b, const char* const e) {
  if (b == 0) {
    test_status = EXIT_FAILURE;
    fprintf(stderr, "%s\n", e);
  }
  return b;
}  // end of check

int main(const int argc, const char* const* argv) {
  if (check(argc == 3, "expected three arguments") == 0) {
    return EXIT_FAILURE;
  }
  mgis_bv_Behaviour* b;
  mgis_bv_BehaviourData* d;
  check_status(mgis_bv_load_behaviour(&b, argv[1], argv[2], "Tridimensional"));
  check_status(mgis_bv_allocate_behaviour_data(&d, b));
  check_status(mgis_bv_free_behaviour_data(&d));
  check_status(mgis_bv_free_behaviour(&b));
  return test_status;
} // end of main