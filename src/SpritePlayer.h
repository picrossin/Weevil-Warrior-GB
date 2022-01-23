#define JUMP_ACCEL    -3
#define WALL_JUMP_UP  -4
#define WALL_JUMP_OUT  9
#define MAX_JUMP_ACCEL 2
#define GRAVITY        1
#define GRAVITY_WAIT   3
#define MAX_RUN_SPEED  2
#define RUN_WAIT       0

#define GRAIN_WAIT 100

#define FALSE 0
#define TRUE  1

typedef enum {
    GROUNDED,
    IN_AIR
} CONTROL_STATE;