/*
 * function: func_021FED08
 * address: 0x021FED08
 * packet: pkt_ov186_021FED08
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FE90C 0x021FE90C thumb ov186
 *   func_021FE970 0x021FE970 thumb ov186
 *   func_021FE9D4 0x021FE9D4 thumb ov186
 *   func_021FEB1C 0x021FEB1C thumb ov186
 *   func_021FEC14 0x021FEC14 thumb ov186
 */
typedef unsigned int   u32;
extern int func_021FE90C(u32 *p, u32 *state);
extern int func_021FE970(u32 *p, u32 *state);
extern int func_021FE9D4(char *p, int *state);
extern int func_021FEB1C(char *p, int *state);
extern int func_021FEC14(char *p, int *state);
void *func_021FED08(unsigned index)
{
    switch (index) {
    case 0: return (void *)func_021FE90C;
    case 1: return (void *)func_021FE970;
    case 2: return (void *)func_021FE9D4;
    case 3: return (void *)func_021FEB1C;
    case 4: return (void *)func_021FEC14;
    }
    return 0;
}
