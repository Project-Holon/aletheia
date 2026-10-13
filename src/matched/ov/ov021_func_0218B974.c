/*
 * function: FIELD_BUILDMODEL_RegisterObjects
 * address:  0x0218B974
 * packet:   pkt_ov021_0218B974
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The const on s is load-bearing: with a plain Src * the compiler keeps
 * &s[i] in a register and spills s; const keeps s and i*16 in registers.
 *
 * symbols:
 *   FIELD_BUILDMODEL_RegisterObject  0x0218BA04  thumb  ov021
 *   FIELD_BUILDMODEL_GetPlacementPosition  0x0218B930  thumb  ov021
 *   FIELD_BUILDMODEL_AddEntry  0x0218C4A0  thumb  ov021
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

void FIELD_BUILDMODEL_RegisterObject(void *p, int a, const Src *s, int d);
int FIELD_BUILDMODEL_GetPlacementPosition(void *p, int id, Vec *pos, int *k);
void FIELD_BUILDMODEL_AddEntry(void *p, int a, Args *args, int d);

int FIELD_BUILDMODEL_RegisterObjects(void *p, int a, const Src *s, int n)
{
    Args args;
    int i;
    int cnt = 0;
    for (i = 0; i < n; i++) {
        FIELD_BUILDMODEL_RegisterObject(p, a, s + i, cnt);
        if (FIELD_BUILDMODEL_GetPlacementPosition(p, (unsigned short)(s[i].lo + (s[i].hi << 8)), &args.pos, &args.k) == 1) {
            cnt++;
            args.w = s[i].w;
            args.pos.x += s[i].x;
            args.pos.y += s[i].y;
            args.pos.z -= s[i].z;
            FIELD_BUILDMODEL_AddEntry(p, a, &args, cnt);
        }
        cnt++;
    }
    return cnt;
}
