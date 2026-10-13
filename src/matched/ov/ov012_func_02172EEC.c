/*
 * function: UNION_COMM_UpdateConnectSync
 * address:  0x02172EEC
 * packet:   pkt_ov012_02172EEC
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0200FB24  0x0200FB24  thumb
 *   UNION_COMMAND_SendConnectSync  0x021739CC  thumb  ov012
 *   func_02080D24  0x02080D24  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_0203D378  0x0203D378  arm
 *   func_02172D38  0x02172D38  thumb  ov012
 */

typedef unsigned char u8;

typedef struct {
    u8 pad[0x5E];
    u8 f5E;
    u8 step : 7;
    u8 active : 1;
} Sub;

typedef struct {
    u8 pad[0x2830];
    Sub sub;
} Work;

typedef unsigned int   u32;
extern u32 func_0200FB24(void);
extern int UNION_COMMAND_SendConnectSync(void);
extern int func_02080D24(u8 a);
extern int func_0203D1B4(void);
extern void func_0203D7BC(u8 a0);
extern u32 func_0203D378(void);
extern void func_02172D38(u8 *p);

void UNION_COMM_UpdateConnectSync(Work *w)
{
    Sub *s = &w->sub;

    if (s->active == 0) {
        return;
    }
    if (func_0200FB24() != 0) {
        return;
    }
    switch (s->step) {
    case 0:
        if (UNION_COMMAND_SendConnectSync() == 1) {
            s->step++;
        }
        break;
    case 1:
        if (func_02080D24(s->f5E) >= func_0203D1B4()) {
            func_0203D7BC(0);
            s->step++;
        }
        break;
    case 2:
        if (func_0203D378() == 1) {
            if (func_0203D1B4() <= 1) {
                func_02172D38((u8 *)w);
                s->step++;
            }
        } else {
            func_02172D38((u8 *)w);
            s->step++;
        }
        break;
    }
}
