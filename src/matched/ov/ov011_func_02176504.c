/*
 * function: func_02176504
 * address:  0x02176504
 * packet:   pkt_ov011_02176504
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     loads overlay 93 (id 0x5D) in state 2 and passes two ov093-resident
 *           data addresses; they carry an ov093 token for that reason.
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02031330  0x02031330  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_020399A8  0x020399A8  arm
 *   func_02013790  0x02013790  thumb
 *   func_02013128  0x02013128  thumb
 *   func_02039338  0x02039338  arm
 *   func_0203A424  0x0203A424  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_0203A574  0x0203A574  arm
 *   func_02031348  0x02031348  arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203A5E4  0x0203A5E4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_020130DC  0x020130DC  thumb
 *   ov093_id       0x0000005D  data  a1
 *   d_021F03C4     0x021F03C4  data  ov093  a4
 *   d_021EFDAC     0x021EFDAC  data  ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 w0;
    u8 b4;
} Obj;

typedef struct {
    u8 pad0[0xC];
    int w0C;
    u8 pad10[0x8];
    u16 h18;
    u8 pad1A[0x7];
    u8 b21;
    u8 pad22[0x76 - 0x22];
    u16 h76;
    u8 pad78[0x84 - 0x78];
    u16 h84;
    u8 pad86[0xF4 - 0x86];
    u32 wF4;
    u32 wF8;
    int wFC;
} Work;

extern int func_020120F4(u32 a);
extern void func_02012138(u32 a);
extern int func_02031330(u32 a);
extern u32 func_0200FB24(void);
extern int func_0203CDBC(void);
extern int func_020399A8(void);
extern void func_02013790(Work *w, int a, int b, int c, int d);
extern void func_02013128(Work *w, u32 a, int b);
extern u16 func_02039338(void);
extern void func_0203A424(int a, int b, int c, u16 d);
extern int func_02039CB4(int a, int b, int c);
extern void func_02034AC4(void *id);
extern void func_0203A574(int a, void *b, int c, int d);
extern void func_02031348(u32 a, int b, void *c, Work *w);
extern int func_0203CD98(void);
extern void func_0203A5E4(u32 key);
extern void func_02034A5C(void *id);
extern void func_020130DC(Work *w);
extern char d_021F03C4[];
extern u8 ov093_id[];
extern char d_021EFDAC[];

int func_02176504(void *a0, int *state, Obj *obj, Work *work)
{
    int h;
    int busy;

    h = func_020120F4(obj->w0);
    func_02012138(obj->w0);
    busy = func_02031330(work->wF4);
    if (func_0200FB24() != 0 || func_0203CDBC() == 1) {
        if (*state > 0 && *state < 6) {
            *state = 7;
        }
    }
    switch (*state) {
    case 0:
        func_02013790(work, h, func_020399A8(), 1, 4);
        func_02013128(work, work->wF8, 0);
        if (func_02039338() < obj->b4) {
            work->b21 = 0;
        } else {
            work->b21 = 1;
        }
        work->w0C = 15;
        work->h18 = 0x490;
        work->h84 = (1 << obj->b4) | (1 << func_02039338());
        work->h76 = 30;
        (*state)++;
        break;
    case 1:
        func_0203A424(func_020399A8(), 0x15, 2, (1 << obj->b4) | (1 << func_02039338()));
        (*state)++;
        break;
    case 2:
        if (func_02039CB4(func_020399A8(), 0x15, 2) == 1) {
            func_02034AC4(ov093_id);
            work->wFC = 1;
            func_0203A574(0x100, d_021F03C4, 9, 0);
            (*state)++;
        }
        break;
    case 3:
        func_0203A424(func_020399A8(), 0x16, 2, (1 << obj->b4) | (1 << func_02039338()));
        (*state)++;
        break;
    case 4:
        if (func_02039CB4(func_020399A8(), 0x16, 2) == 1) {
            (*state)++;
        }
        break;
    case 5:
        func_02031348(work->wF4, -1, d_021EFDAC, work);
        (*state)++;
        break;
    case 6:
        if (busy == 0) {
            (*state)++;
        }
        break;
    case 7:
        if (work->wFC == 1) {
            if (func_0203CD98() == 1) {
                func_0203A5E4(0x100);
            }
            func_02034A5C(ov093_id);
        }
        func_020130DC(work);
        return 1;
    }
    return 0;
}
