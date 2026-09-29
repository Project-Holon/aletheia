/*
 * function: func_0216F174
 * address:  0x0216F174
 * packet:   pkt_ov010_0216F174
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216F244  0x0216F244  thumb  ov010
 *   func_0216F288  0x0216F288  thumb
 *   func_0216F2B4  0x0216F2B4  thumb
 *   func_0216F2E0  0x0216F2E0  thumb
 *   func_0216F31C  0x0216F31C  thumb
 *   func_0216F378  0x0216F378  thumb
 *   func_0216F3B0  0x0216F3B0  thumb
 */

extern int func_0216F244(int a, int b);
extern int func_0216F288(int a);
extern int func_0216F2B4(int a);
extern int func_0216F2E0(int a);
extern int func_0216F31C(int a);
extern int func_0216F378(int a);
extern int func_0216F3B0(int a);

int func_0216F174(int a, int *b, int c, int d)
{
    switch (*b) {
    case 0:
        *b = func_0216F244(d, c);
        break;
    case 1:
        *b = func_0216F288(d);
        break;
    case 2:
        *b = func_0216F2B4(d);
        break;
    case 3:
        *b = func_0216F2E0(d);
        break;
    case 4:
        *b = func_0216F31C(d);
        break;
    case 5:
        *b = func_0216F378(d);
        break;
    case 6:
        *b = func_0216F3B0(d);
        break;
    case 7:
    default:
        return 1;
    }
    return 0;
}
