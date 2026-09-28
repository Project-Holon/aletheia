/*
 * function: ghiPostCleanupState
 * address:  0x021C2BB0
 * packet:   pkt_ov114_021C2BB0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiPostCleanupState (ghttppost)
 *
 * symbols:
 *   ArrayLength             0x02184200  arm
 *   ArrayNth                0x02184208  arm
 *   ArrayFree               0x021841B0  arm
 *   ghiPostStateCleanup     0x021C2A3C  arm  ov114
 *   ghiFreePost             0x021C2464  arm  ov114
 */

typedef struct GHIPostState GHIPostState;

typedef struct {
    char pad0[0x18];
    int field18;
} GHIPost;

typedef struct {
    char pad0[0x164];
    GHIPost *field164;
    void *field168;
} GHIConnection;

extern int ArrayLength(void *array);
extern void *ArrayNth(void *array, int n);
extern void ArrayFree(void *array);
extern void ghiPostStateCleanup(GHIPostState *state);
extern void ghiFreePost(GHIPost *post);

void ghiPostCleanupState(GHIConnection *connection)
{
    int i;
    int len;

    if (connection->field168 != 0)
    {
        len = ArrayLength(connection->field168);
        for (i = 0; i < len; i++)
        {
            GHIPostState *state = ArrayNth(connection->field168, i);
            ghiPostStateCleanup(state);
        }
        ArrayFree(connection->field168);
        connection->field168 = 0;
    }
    if (connection->field164 != 0 && connection->field164->field18 != 0)
    {
        ghiFreePost(connection->field164);
        connection->field164 = 0;
    }
}
