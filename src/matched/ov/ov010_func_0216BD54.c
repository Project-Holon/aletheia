/*
 * function: func_0216BD54
 * address:  0x0216BD54
 * packet:   pkt_ov010_0216BD54
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: reads a species and a flag value and two result
 * variables, maps the event species (243-245, 251, 492, 647-649) to a kind
 * and, for 647/648, a signature move (548/547, dropped when the flag is 0),
 * and stores func_0216BE20's answer in the second variable; any other
 * species stores 0.
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0216BE20  0x0216BE20  thumb  ov010
 */

typedef unsigned short u16;

extern void *func_0215A5E4(void *work);
extern void *func_02012934(void *p);
extern u16   func_02159B10(void *ctx, void *work);
extern u16 *func_02159AE8(void *ctx, void *work);
extern u16   func_0216BE20(void *s, int species, int move, int kind, u16 *out);

int func_0216BD54(void *ctx, void *work)
{
    void *s = func_02012934(func_0215A5E4(work));
    u16 species = func_02159B10(ctx, work);
    u16 flag = func_02159B10(ctx, work);
    u16 *out = func_02159AE8(ctx, work);
    u16 *res = func_02159AE8(ctx, work);
    int kind;
    int move;

    switch (species) {
    case 647:
        kind = 4;
        move = 548;
        break;
    case 648:
        kind = 5;
        move = 547;
        break;
    case 251:
        kind = 0;
        move = 0;
        break;
    case 243:
    case 244:
    case 245:
        kind = 2;
        move = 0;
        break;
    case 649:
        kind = 6;
        move = 0;
        break;
    case 492:
        kind = 7;
        move = 0;
        break;
    default:
        *res = 0;
        return 0;
    }
    if (flag == 0) {
        move = 0;
    }
    *res = func_0216BE20(s, species, move, kind, out);
    return 0;
}
