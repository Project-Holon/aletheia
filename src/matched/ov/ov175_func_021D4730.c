/*
 * function: func_021D4730
 * address: 0x021D4730
 * packet: pkt_ov175_021D4730
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_02009448 0x02009448 thumb
 *   func_020092EC 0x020092EC thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_021DC738 0x021DC738 thumb ov175
 *   func_021DC77C 0x021DC77C thumb ov175
 *   func_021DC8A0 0x021DC8A0 thumb ov175
 *   func_021D61A4 0x021D61A4 thumb ov175
 *   func_021D4608 0x021D4608 thumb ov175
 *   func_021D9F04 0x021D9F04 thumb ov175
 *   func_021D63DC 0x021D63DC thumb ov175
 *   func_021D6788 0x021D6788 thumb ov175
 *   func_021D61F0 0x021D61F0 thumb ov175
 *   func_021D679C 0x021D679C thumb ov175
 *   func_021D61CC 0x021D61CC thumb ov175
 *   func_021D495C 0x021D495C thumb ov175
 */
typedef unsigned int u32;
typedef unsigned char u8;
struct Big;
struct Sub02009448Obj;
struct Sub02009210Obj;
extern void *GAME_DATA_GetSaveControl(struct Big *);
extern struct Sub02009448Obj *func_02009448(void *);
extern u8 func_020092EC(const struct Sub02009210Obj *);
extern void func_02082BCC(void *, int, int);
extern void func_021E8738(int *, int, int, int);
extern void func_021E8AB4(u32, u32);
extern void func_021E8AA0(int *, int);
extern int func_021E8844(const int *);
extern void func_021E8AB8(u32);
extern void func_021DC738(char *, unsigned);
extern int func_021DC77C(u8 *p);
extern void func_021DC8A0(char *, void *);
extern void func_021D61A4(void *obj, int unused, u8 *p);
extern void func_021D4608(u32 sys, int *state, u32 *p);
extern int func_021D9F04(char *, void *, void *);
extern void func_021D63DC(char *);
extern void func_021D6788(char *, void *);
extern void func_021D61F0(u32 sys, int *state, char *p);
extern u32 func_021D679C(char *);
extern void func_021D61CC(void *a, u32 **pp, char *p);
extern void func_021D495C(u32 sys, int *state, u32 *p);
void func_021D4730(u32 sys, int *state, u32 *p)
{
    u32 *ctx = (u32 *)p[16];
    u32 result;
    switch (*state) {
    case 0:
        if (func_020092EC((const struct Sub02009210Obj *)func_02009448(GAME_DATA_GetSaveControl((struct Big *)*(u32 *)ctx[2])))) *state = 1;
        else *state = 6;
        break;
    case 1: func_021E8738((int *)p[9], p[4], 41, 1); *state = 14; func_021E8AB4(sys, 2); break;
    case 2: func_021E8738((int *)p[9], p[4], 24, 2); *state = 14; func_021E8AB4(sys, 3); break;
    case 3: func_02082BCC((void *)ctx[12], 0, 8); func_021DC738((char *)p[12], 87); *state = 4; break;
    case 4:
        switch (func_021DC77C((u8 *)p[12])) {
        case 0: break;
        case 1: func_021DC8A0((char *)p[12], (void *)((u32 *)p[16])[12]); *state = 5; break;
        case 3: func_02082BCC((void *)((u32 *)p[16])[12], 0, 8); func_021E8AA0((int *)sys, (int)func_021D61A4); break;
        case 2:
            switch (func_021D9F04((char *)p[12], 0, 0)) {
            case 2: func_021E8AA0((int *)sys, (int)func_021D61A4); break;
            case 1: func_021D63DC((char *)p); func_021E8AA0((int *)sys, (int)func_021D4608); break;
            }
            break;
        }
        break;
    case 5: if (((u8 *)ctx[12])[6]) *state = 9; else *state = 6; break;
    case 6: func_021E8738((int *)p[9], p[4], 55, 1); *state = 14; func_021E8AB4(sys, 12); break;
    case 9:
        func_021D6788((char *)p, func_021D61F0); *state = 10;
        switch (func_021D9F04((char *)p[12], 0, 0)) {
        case 1: func_021D63DC((char *)p); func_021E8AA0((int *)sys, (int)func_021D4608); break;
        case 2: func_021E8AA0((int *)sys, (int)func_021D61A4); break;
        }
        break;
    case 10:
        result = func_021D679C((char *)p);
        if (result == 0) *state = 13;
        else if (result == 1) *state = 11;
        else if (result == 3) func_021E8AA0((int *)sys, (int)func_021D61A4);
        if (result != 0xffff) {
            switch (func_021D9F04((char *)p[12], 0, 0)) {
            case 1: func_021D63DC((char *)p); func_021E8AA0((int *)sys, (int)func_021D4608); break;
            case 2: func_021E8AA0((int *)sys, (int)func_021D61A4); break;
            }
        }
        break;
    case 11: func_021E8738((int *)p[9], p[4], 120, 1); *state = 14; func_021E8AB4(sys, 12); break;
    case 12: func_021E8AA0((int *)sys, (int)func_021D61CC); break;
    case 13: func_021E8AA0((int *)sys, (int)func_021D495C); break;
    case 14: if (func_021E8844((int *)p[9])) func_021E8AB8(sys); break;
    }
}
