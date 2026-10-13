/*
 * function: func_021FDD60
 * address: 0x021FDD60
 * packet: pkt_ov094_021FDD60
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: declare count before n to place them at sp+0x18 and sp+0x14;
 *   reversed declarations produced five differing spill/reload bytes.
 * symbols:
 *   func_021FCD14 0x021FCD14 thumb ov094
 *   func_021F8710 0x021F8710 thumb ov094
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   PARTICLE_StartEffectWithCallback 0x020515CC arm
 *   func_021FD1CC 0x021FD1CC thumb ov094
 *   d_0220AE68 0x0220AE68 data ov094 a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { unsigned low:6; unsigned b6:1; } Flags;
typedef struct {
    Flags flags;
    char pad04[8];
    int *objects[16];
    char pad4c[0x90];
    int dc;
    char pade0[0x158];
    u16 heap;
    char pad23a[0xe];
    u8 kind;
    char pad249[0xf];
    u16 f258;
} State;
typedef struct { int v[23]; } Rec;
extern char d_0220AE68[];
extern int func_021FCD14(State *, int, int *);
extern int func_021F8710(void);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020307B0(void *p);
extern int PARTICLE_StartEffectWithCallback(int *, int, int, int);
extern void func_021FD1CC(void *p);

void func_021FDD60(State *s, Rec *r, int slot, int arg)
{
    int targets[8];
    int keys[8];
    int count;
    int n;
    int i;
    Rec *p;

    if (r->v[2] == r->v[1] && (u32)(r->v[2] - 11) <= 1) {
        if (r->v[2] == 12)
            r->v[22] = 1;
        count = func_021FCD14(s, 16, targets);
        if (count != 0) {
            for (i = 0; i < count; i++) {
                p = func_02030734((u16)((s->heap & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x1c0e);
                *p = *r;
                p->v[1] = targets[i];
                p->v[2] = targets[i];
                if (PARTICLE_StartEffectWithCallback(s->objects[slot], arg, (int)func_021FD1CC, (int)p) == -1)
                    func_020307B0(p);
            }
        }
    } else if (r->v[2] == r->v[1] && s->kind == 12 && !s->flags.b6 && s->f258 != 0x16e && (u32)(r->v[2] - 9) <= 1) {
        if (r->v[2] == 10)
            r->v[22] = 1;
        switch (func_021F8710()) {
        default:
        case 0: case 3:
            keys[0] = s->dc;
            n = 1;
            break;
        case 1:
            keys[0] = (s->dc & 1) ? 1 : 0;
            n = 1;
            break;
        case 2:
            keys[0] = (s->dc & 1) ? 19 : 18;
            keys[1] = (s->dc & 1) ? 21 : 20;
            n = 2;
            break;
        }
        if (n != 0) {
            for (i = 0; i < n; i++) {
                p = func_02030734((u16)((s->heap & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x1c45);
                *p = *r;
                p->v[1] = keys[i];
                p->v[2] = keys[i];
                if (PARTICLE_StartEffectWithCallback(s->objects[slot], arg, (int)func_021FD1CC, (int)p) == -1)
                    func_020307B0(p);
            }
        }
    } else {
        p = func_02030734((u16)((s->heap & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x1c56);
        *p = *r;
        if (PARTICLE_StartEffectWithCallback(s->objects[slot], arg, (int)func_021FD1CC, (int)p) == -1)
            func_020307B0(p);
    }
}
