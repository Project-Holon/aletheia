/*
 * function: func_0215B5A8
 * address:  0x0215B5A8
 * packet:   pkt_0215B5A8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   POKE_TOOL_HealParty  0x0201BA34  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5E4(void *a0);
struct BigObj;
extern void *func_02012934(const struct BigObj *p);
extern void POKE_TOOL_HealParty(void *a0);

int func_0215B5A8(int a0, int a1)
{
    void *v0;
    void *v1;

a0 = a1 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215B5B0:
    v1 = func_02012934(v0);
loc_0215B5B4:
    POKE_TOOL_HealParty(v1);
loc_0215B5B8:
a0 = 0;
    return a0;}
