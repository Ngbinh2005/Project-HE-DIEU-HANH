#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    if (argc < 3) {
        fprintf(2, "Usage: trace mask command [arguments]\n");
        exit(1);
    }

    // Convert the first argument to the mask integer
    int mask = atoi(argv[1]);

    // Enable tracing with the given mask
    if (trace(mask) < 0) {
        fprintf(2, "trace: failed to enable tracing\n");
        exit(1);
    }

    // Execute the specified command
    exec(argv[2], &argv[2]);

    // If exec fails, print an error
    fprintf(2, "trace: exec %s failed\n", argv[2]);
    exit(1);
} 