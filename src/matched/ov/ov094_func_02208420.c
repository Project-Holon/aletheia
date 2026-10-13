/*
 * function: func_02208420
 * address: 0x02208420
 * packet: pkt_ov094_02208420
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 0220854E..02208550 is two bytes of zero alignment padding.
 * lever: separate array stores avoid a reload; an enum VRAM base fixes
 *   add order; zero the loop counter before assigning that base.
 * symbols:
 *   CLACT_GetActorImageProxy 0x0204B7C8 arm
 *   func_02082A60 0x02082A60 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int w[9]; } Struct36;
typedef struct { char p0[0x14]; char *f14; } O;
typedef struct { char p0[4]; void *f4; char p8[0x44]; int f4c; } E;
struct Struct36;
extern void CLACT_GetActorImageProxy(const char *src, struct Struct36 *dst);
extern void func_02082A60(const void *, void *, u32);
void func_02208420(const O *o, E *e, int v)
{
    Struct36 buf;
    u16 current[3];
    u16 maximum[3];
    int i, n, j;
    enum { VRAM = 0x06400000 } base;
    if (e->f4 != 0) {
        CLACT_GetActorImageProxy(e->f4, (struct Struct36 *)(&buf));
        for (i = 0; i < 3; i++) {
            current[i] = 0x660;
            maximum[i] = 0x660;
        }
        if (v >= 100) {
            current[0] = v / 100 * 32 + 0x520;
            v %= 100;
        }
        if (v >= 10 || current[0] != 0x660) {
            current[1] = v / 10 * 32 + 0x520;
            v %= 10;
        }
        current[2] = v * 32 + 0x520;
        n = e->f4c;
        j = 0;
        if (n >= 100) {
            maximum[j] = n / 100 * 32 + 0x520;
            n %= 100;
            j++;
        }
        if (n >= 10 || j != 0) {
            maximum[j] = n / 10 * 32 + 0x520;
            n %= 10;
            j++;
        }
        maximum[j] = n * 32 + 0x520;
        i = 0;
        base = VRAM;
        for (; i < 3; i++) {
            func_02082A60(o->f14 + current[i], (void *)(buf.w[1] + (base + i * 32)), 32);
            func_02082A60(o->f14 + maximum[i], (void *)(buf.w[1] + (base + (i + 4) * 32)), 32);
        }
    }
}
