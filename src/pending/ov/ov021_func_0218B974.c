/*
 * function: func_0218B974
 * address:  0x0218B974
 * packet:   pkt_ov021_0218B974
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: logic matches the listing. Allocation differs: the original
 * keeps i spilled at sp+8 from entry, s in r5 and i*16 in r6, recomputing
 * s + i*16 at each use; this C CSEs &s[i] into r5 and spills s. Tried decl
 * orders, pointer arithmetic, ++cnt, and an inline success helper.
 *
 * symbols:
 *   func_0218BA04  0x0218BA04  thumb  ov021
 *   func_0218B930  0x0218B930  thumb  ov021
 *   func_0218C4A0  0x0218C4A0  thumb  ov021
 */

typedef struct {
    int x;
    int y;
    int z;
    unsigned short w;
    unsigned char hi;
    unsigned char lo;
} Src;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct {
    int k;
    Vec pos;
    unsigned short w;
} Args;

void func_0218BA04(void *p, int a, Src *s, int d);
int func_0218B930(void *p, int id, Vec *pos, int *k);
void func_0218C4A0(void *p, int a, Args *args, int d);

int func_0218B974(void *p, int a, Src *s, int n)
{
    Args args;
    int i;
    int cnt = 0;
    for (i = 0; i < n; i++) {
        func_0218BA04(p, a, &s[i], cnt);
        if (func_0218B930(p, (unsigned short)(s[i].lo + (s[i].hi << 8)), &args.pos, &args.k) == 1) {
            cnt++;
            args.w = s[i].w;
            args.pos.x += s[i].x;
            args.pos.y += s[i].y;
            args.pos.z -= s[i].z;
            func_0218C4A0(p, a, &args, cnt);
        }
        cnt++;
    }
    return cnt;
}
