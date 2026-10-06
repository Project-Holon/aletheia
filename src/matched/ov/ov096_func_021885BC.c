/*
 * function: func_021885BC
 * address: 0x021885BC
 * packet: pkt_ov096_021885BC
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: case 2 falls into default; an empty case 2 break adds four bytes.
 * Caller-visible return overrides tail-forwarders; 0201127C keeps visible r1.
 * symbols:
 *   func_021D5584 0x021D5584 thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021B9A6C 0x021B9A6C thumb ov093
 *   func_0218A494 0x0218A494 thumb ov096
 *   func_0218A528 0x0218A528 thumb ov096
 *   func_0218A384 0x0218A384 thumb ov096
 *   func_0201127C 0x0201127C thumb
 *   func_02011290 0x02011290 thumb
 *   func_02011298 0x02011298 thumb
 *   func_020870D0 0x020870D0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct { u8 state, index; u16 move; int scores[4]; u8 p14[0x28]; u32 mask, all; u8 flags, entry, slot, target; u8 p48[0x4c]; u8 side, opp; u8 p96[2]; int mode; u8 p9c[0x10]; void *script; int fb0, fb4, fb8; u8 *fbc; int fc0, fc4; u8 pc8[8]; u64 tick; } Obj;
struct UtilWork;
extern u8 func_021D5584(struct UtilWork *p, u32 i);
extern u16 func_021D54C0(u8 *p, int i);
struct QG;
struct ScriptVm;
extern u8 func_021D5448(struct QG *p);
extern int func_021B9A6C(int, u32);
extern void *func_0218A494(u8 *);
extern void func_0218A528(u8 *);
extern int func_0218A384(Obj *, int, int);
extern void func_0201127C(struct ScriptVm *vm, u8 *pc);
extern void func_02011290(struct ScriptVm *vm);
extern int func_02011298(struct ScriptVm *vm);
extern u64 func_020870D0(void);
void func_021885BC(int a, Obj *b)
{
    while (b->state != 2 && !(b->flags & 16)) {
        switch (b->state) {
        case 0:
            if (func_021D5584((struct UtilWork *)b->fbc, b->index) == 0) {
                b->move = 0;
            } else {
                b->move = func_021D54C0(b->fbc, b->index);
                b->script = func_0218A494((u8 *)b);
                func_0201127C((struct ScriptVm *)a, b->script);
            }
            b->state++;
        case 1:
            if (b->mode == 2 && b->move != 0 && func_021B9A6C(b->side, b->opp) == 0 && func_0218A384(b, b->move, 11) == 0) {
                b->move = 0;
                func_02011290((struct ScriptVm *)a);
                func_0218A528((u8 *)b);
                b->script = 0;
            }
            if (b->move != 0) {
                func_02011298((struct ScriptVm *)a);
                if (b->flags & 1) {
                    b->flags &= ~16;
                    func_0218A528((u8 *)b);
                    b->script = 0;
                } else if (func_020870D0() - b->tick > 500) {
                    b->flags |= 16;
                    break;
                }
            } else {
                b->scores[b->index] = 0;
                b->flags |= 1;
            }
            if (b->flags & 1) {
                b->index++;
                if (b->index < func_021D5448((struct QG *)b->fbc) && !(b->flags & 8))
                    b->state = 0;
                else
                    b->state++;
                b->flags &= ~1;
            }
            break;
        case 2:
        default:
            b->state = 2;
            break;
        }
    }
}
