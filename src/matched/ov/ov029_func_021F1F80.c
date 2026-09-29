/*
 * function: func_021F1F80
 * address:  0x021F1F80
 * packet:   pkt_ov029_021F1F80
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0203F4CC  0x0203F4CC  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0204B918  0x0204B918  arm
 *   func_0204B908  0x0204B908  arm
 *   func_02085D3C  0x02085D3C  arm
 *   func_021F1F70  0x021F1F70  thumb  ov029
 *   func_0203568C  0x0203568C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 hour;
    u32 minute;
    u32 second;
} RtcTime;

extern void func_0203F4CC(RtcTime *t);
extern void func_0204B3DC(int, int);
extern int func_0204B918(int o);
extern void func_0204B908(int o, u16 v);
extern int func_02085D3C(void);
extern u8 func_021F1F70(void);
extern int func_0203568C(void);

static inline void SetFrame(int o, int v)
{
    if (v != func_0204B918(o)) {
        func_0204B908(o, v);
    }
}

void func_021F1F80(char *p)
{
    RtcTime t;
    int o;
    int v;

    func_0203F4CC(&t);
    func_0204B3DC(*(int *)(p + 0x12c), 0);

    o = *(int *)(p + 0x130);
    v = t.hour / 10;
    SetFrame(o, v);
    if (v == 0) {
        func_0204B3DC(o, 0);
    } else {
        func_0204B3DC(o, 1);
    }

    o = *(int *)(p + 0x134);
    v = t.hour % 10;
    SetFrame(o, v);
    o = *(int *)(p + 0x138);
    v = t.second & 1;
    SetFrame(o, v);
    o = *(int *)(p + 0x13c);
    v = t.minute / 10;
    SetFrame(o, v);
    o = *(int *)(p + 0x140);
    v = t.minute % 10;
    SetFrame(o, v);

    o = *(int *)(p + 0x144);
    if (func_02085D3C()) {
        SetFrame(o, func_021F1F70());
    } else {
        SetFrame(o, func_0203568C() == 5);
    }
}
