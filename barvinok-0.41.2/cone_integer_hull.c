#include <barvinok/polylib.h>
#include <barvinok/options.h>
#include "hull.h"

int main(int argc, char **argv)
{
    Matrix *M;
    Polyhedron *C;
    struct barvinok_options *options = barvinok_options_new_with_defaults();

    argc = barvinok_options_parse(options, argc, argv, ISL_ARG_ALL);

    M = Matrix_Read();
    C = Constraints2Polyhedron(M, options->MaxRays);
    Matrix_Free(M);

    M = Cone_Integer_Hull(C, NULL, 0, options);

    Polyhedron_Free(C);

    Matrix_Print(stdout, P_VALUE_FMT, M);
    Matrix_Free(M);

    if (options->print_stats)
	barvinok_stats_print(options->stats, stdout);

    barvinok_options_free(options);
    return 0;
}
