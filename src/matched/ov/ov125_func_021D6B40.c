/*
 * function: func_021D6B40
 * address:  0x021D6B40
 * packet:   pkt_ov125_021D6B40
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 2026-10-05 (wD9r lane109): EXACT. The 0x55F1 inner switch is written out as an expanded inline:
 *   r = 0; cases 0..2 set r and break; case 3 sets t and `goto join`; then `t = r; join: ret = t;`.
 *   t is declared first, so the merged ret/t/r value keeps an early local's spill slot ([sp,#8]);
 *   a real static inline helper put it in the inline return temp's slot ([sp]).
 *
 * symbols:
 *   func_021D7700  0x021D7700  thumb  ov125
 *   func_021D7154  0x021D7154  thumb  ov125
 *   func_021D75C0  0x021D75C0  thumb  ov125
 *   func_021D860C  0x021D860C  arm  ov125
 *   func_021D8654  0x021D8654  arm  ov125
 *   func_021D8694  0x021D8694  arm  ov125
 *   func_021D8754  0x021D8754  arm  ov125
 *   func_021D879C  0x021D879C  arm  ov125
 *   func_021D87FC  0x021D87FC  arm  ov125
 *   func_021D885C  0x021D885C  arm  ov125
 *   func_021D88BC  0x021D88BC  arm  ov125
 *   func_021D88F0  0x021D88F0  arm  ov125
 *   func_021B9748  0x021B9748  thumb  ov114
 *   func_021B9774  0x021B9774  thumb  ov114
 *   func_021B9790  0x021B9790  thumb  ov114
 *   func_021B97F4  0x021B97F4  thumb  ov114
 *   func_021B9800  0x021B9800  thumb  ov114
 *   func_021B9838  0x021B9838  thumb  ov114
 *   func_021B98A0  0x021B98A0  thumb  ov114
 *   func_021B98D8  0x021B98D8  thumb  ov114
 *   func_021B98F8  0x021B98F8  thumb  ov114
 *   func_021B99B8  0x021B99B8  thumb  ov114
 *   func_021B99DC  0x021B99DC  thumb  ov114
 *   func_021B99F0  0x021B99F0  thumb  ov114
 *   func_021B99F4  0x021B99F4  thumb  ov114
 *   func_021B9A14  0x021B9A14  thumb  ov114
 *   func_0200853C  0x0200853C  thumb
 *   MSGDATA_ReadUnits  0x02045F5C  arm
 *   BATTLE_REC_GetModeLayout  0x0200B784  thumb
 *   BATTLE_REC_GetBody  0x0200B91C  thumb
 *   BATTLE_REC_SetBodyCrc  0x0200BA44  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   d_021D8D28  0x021D8D28  data a4
 *   d_020A7370  0x020A7370  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_021D8D28[];
extern void *d_020A7370;
extern char *func_021D7700(void);
extern int func_021D7154(int, int, int *, int *);
extern void func_021D75C0(void);
extern int func_021D860C(void *, u32);
struct Big;
struct MsgData;
struct RecC4;
struct Sub0200852CObj;
extern int func_021D8654(int value, int n);
extern int func_021D8694(u32, void *, u32, u32);
extern int func_021D8754(void *, u32);
extern int func_021D879C(int value, int n);
extern int func_021D87FC(int value, int n);
extern int func_021D885C(int value, int n);
extern int func_021D88BC(u32, u32, u32, u32);
extern int func_021D88F0(u32, u32, u32);
extern int func_021B9748(u8 *);
extern void func_021B9774(u8 *);
extern int func_021B9790(u8 *);
extern u8 *func_021B97F4(u8 *);
extern u8 *func_021B9800(int a, int b, int c);
extern void func_021B9838(u8 *);
extern void func_021B98A0(u8 *p, int a, int b, int c);
extern void func_021B98D8(u8 *p, int a, int n);
extern int func_021B98F8(u8 *);
extern void func_021B99B8(u8 *);
extern int func_021B99DC(u8 *);
extern int func_021B99F0(u8 *);
extern u32 func_021B99F4(u32 p, u32 i);
extern u8 *func_021B9A14(u8 *p, u32 i);
extern void func_02082D44(const void *, void *, u32);
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern void BATTLE_REC_GetModeLayout(u16, int *, int *);
extern u8 *BATTLE_REC_GetBody(void);
extern void BATTLE_REC_SetBodyCrc(struct RecC4 *p);
extern u8 *func_02012944(void *p);
extern void *func_02012EBC(struct Big *p);
extern void MSGDATA_ReadUnits(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);

#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))
#define OBJ (*(u8 **)(p + 0x404))

int func_021D6B40(u8 *p, int *done)
{
    int t;
    int n, m;
    int idx, sub;
    int n2, m2;
    int ret;
    int r;
    char *base;
    char *base2;
    int i;
    u8 *h;
    int a, b;
    u8 x;

    *done = 0;
    ret = 0;
    switch (*(int *)(p + 0x3d8)) {
    case 0x5208:
        ret = func_021D860C(p + 0x174, W(0x3ac));
        break;
    case 0x5209:
        ret = func_021D8654(H(0x3a4), W(0x3ac));
        break;
    case 0x55f0:
        switch (B(0x402)) {
        case 0:
            base = func_021D7700();
            if (OBJ != 0)
                func_02034714(d_021D8D28, ret, d_021D8D28);
            OBJ = func_021B9800((u16)W(0x13c), func_0200853C((const struct Sub0200852CObj *)func_02012944((void *)W(0))), W(0x494));
            func_021B98A0(OBJ, (u16)W(0x13c), 0x540, 3);
            BATTLE_REC_GetModeLayout(*(u16 *)(base + 0xa6), &n, &m);
            B(0x490) = 0;
            for (i = 0; i < n; i++) {
                func_021B98D8(OBJ, (int)(base + 0xd00 + i * 0x2a4), *(u16 *)(base + i * 0x2a4 + 0xcfe) * 0x70);
                B(0x490) += (u8)*(u16 *)(base + i * 0x2a4 + 0xcfe);
            }
            if (!func_021B98F8(OBJ))
                func_02034714(d_021D8D28, 0, d_021D8D28);
            if (!(func_021B9748(OBJ) == 0 ? 1 : 0))
                func_02034714(d_021D8D28, 0, d_021D8D28);
            B(0x402)++;
            break;
        case 1:
            a = func_021B99DC(OBJ);
            b = func_021B9790(OBJ);
            if (a != 200 && b != 15) {
                switch (func_021B99DC(OBJ)) {
                case 0x190: B(0x493) = 0x96; break;
                case 0x191: B(0x493) = 0x97; break;
                case 0x198: B(0x493) = 0x98; break;
                default: B(0x493) = 0x99; break;
                }
                func_021B99B8(OBJ);
                func_021B9774(OBJ);
                func_021B9838(OBJ);
                OBJ = 0;
                *done = 1;
                return 1;
            }
            if (b == 0) {
                h = func_021B97F4(OBJ);
                if (func_021B99F0(h) == 0) {
                    B(0x492) = 0;
                    func_02082D44(func_021B9A14(h, B(0x490)), p + 0x40a, 0x80);
                    for (i = 0; i < B(0x490); i++)
                        W(0x48c) = func_021B99F4((u32)h, i);
                    B(0x402)++;
                } else {
                    base2 = func_021D7700();
                    if (B(0x403) == 1)
                        B(0x492) = 1;
                    BATTLE_REC_GetModeLayout(*(u16 *)(base2 + 0xa6), &n2, &m2);
                    for (i = 0; i < B(0x490); i++) {
                        W(0x48c) = func_021B99F4((u32)h, i);
                        if (W(0x48c) != 0 && B(0x403) == 0) {
                            if (!func_021D7154((int)p, i, &idx, &sub))
                                break;
                            {
                                char *e = base2 + 0xd00 + idx * 0x2a4 + sub * 0x70;
                                MSGDATA_ReadUnits(d_020A7370, *(u16 *)(e + 6), (u16 *)(e + 0x32), 11);
                            }
                            W(0x5a0) = 1;
                        }
                    }
                    if (B(0x403) == 0) {
                        BATTLE_REC_SetBodyCrc((struct RecC4 *)BATTLE_REC_GetBody());
                        B(0x402) = 0;
                        B(0x403)++;
                    } else {
                        B(0x402)++;
                    }
                }
                func_021B99B8(OBJ);
                func_021B9838(OBJ);
                OBJ = 0;
                break;
            }
            if (b != 15 && OBJ != 0) {
                func_021B99B8(OBJ);
                func_021B9774(OBJ);
                func_021B9838(OBJ);
                OBJ = 0;
                return 1;
            }
            return 0;
        case 2:
            func_02012EBC((struct Big *)W(0));
            func_021D75C0();
            B(0x402)++;
            break;
        case 3:
            ret = func_021D8694(W(0x174), p + 0x40a, 0x80, W(0x3ac));
            break;
        }
        break;
    case 0x55f1:
        r = 0;
        switch (W(0x3e0)) {
        case 0:
            r = func_021D8754(p + 0x174, W(0x3ac));
            break;
        case 1:
            r = func_021D879C(0x64, W(0x3ac));
            break;
        case 2:
            r = func_021D885C(0x64, W(0x3ac));
            break;
        case 3:
            t = func_021D87FC(0x64, W(0x3ac));
            goto join;
            break;
        }
        t = r;
    join:
        ret = t;
        break;
    case 0x55f2:
        ret = func_021D88BC(W(0x3a4), W(0x3a8), 0x64, W(0x3ac));
        break;
    case 0x55f3:
        ret = func_021D88F0(W(0x3a4), W(0x3a8), W(0x3ac));
        break;
    default:
        func_02034714(d_021D8D28, 0, d_021D8D28);
        break;
    }
    if (ret == 1)
        W(0x3dc) = W(0x3d8);
    return ret;
}
