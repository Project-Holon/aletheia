/*
 * function: func_02073598
 * address:  0x02073598
 * packet:   pkt_02073548
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02060614  0x02060614  arm
 *   func_02060550  0x02060550  arm
 *   g_0214E018     0x0214E018  data
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Obj_02073548 {
    char pad4[4];
    void *f4;
    char pad3d[0x3d - 8];
    u8 b3d;
} Obj_02073548;

extern void *g_0214E018;
extern void *func_02060614(void *list, void *curr);
extern void  func_02060550(void *list, void *curr, void *obj);

void func_02073598(Obj_02073548 *obj)
{
    Obj_02073548 *curr = (Obj_02073548 *)func_02060614(g_0214E018, 0);
    while (curr != 0) {
        if (obj->b3d < curr->b3d) {
            break;
        }
        curr = (Obj_02073548 *)func_02060614(g_0214E018, curr);
    }
    func_02060550(g_0214E018, curr, obj);
}
