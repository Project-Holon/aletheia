/*
 * function: COMM_PLAYER_Delete
 * address:  0x0216754C
 * packet:   pkt_ov010_0216754C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   COMM_PLAYER_Del  0x02167658  thumb  ov010
 *   GAMESYSTEM_IsFieldMapExist  0x02012114  thumb
 *   FIELD_COMM_ACTOR_CTRL_Delete  0x021942C8  thumb  ov021
 *   func_02034714  0x02034714  arm
 *   func_020307B0  0x020307B0  arm
 *   d_02172A28  0x02172A28  data  ov010  a4
 */

struct O {
    int f0;
    int f4;
};

extern void COMM_PLAYER_Del(struct O *o, int i);
struct Ctx;
extern unsigned int GAMESYSTEM_IsFieldMapExist(const struct Ctx *a);
extern void FIELD_COMM_ACTOR_CTRL_Delete(int a);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_020307B0(void *p);
extern const char d_02172A28[];

void COMM_PLAYER_Delete(int a, struct O *o)
{
    int i;
    if (o->f4 != 0) {
        for (i = 0; i < 4; i++)
            COMM_PLAYER_Del(o, i);
        if (GAMESYSTEM_IsFieldMapExist((const struct Ctx *)a) == 1)
            FIELD_COMM_ACTOR_CTRL_Delete(o->f4);
        else
            func_02034714(d_02172A28, 0, d_02172A28);
    }
    func_020307B0(o);
}
