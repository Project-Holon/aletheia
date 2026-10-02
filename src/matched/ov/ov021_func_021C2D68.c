/*
 * function: func_021C2D68
 * address:  0x021C2D68
 * packet:   pkt_ov021_021C2D68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020124F0  0x020124F0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02043678  0x02043678  arm
 *   func_021C2BE4  0x021C2BE4  thumb  ov021
 *   func_021C2F84  0x021C2F84  thumb  ov021
 *   func_020437AC  0x020437AC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02008550  0x02008550  thumb
 *   func_02046BE0  0x02046BE0  arm
 *   d_021DE3E4     0x021DE3E4  data  ov021  a4
 *   d_021DE3F4     0x021DE3F4  data  ov021  a4
 *   d_021DE404     0x021DE404  data  ov021  a4
 *   d_021DE40C     0x021DE40C  data  ov021  a4
 *   d_021DE418     0x021DE418  data  ov021  a4
 *   d_021DE428     0x021DE428  data  ov021  a4
 *   d_021DE43C     0x021DE43C  data  ov021  a4
 *   d_021DE448     0x021DE448  data  ov021  a4
 * Sibling of func_021C27F4. Case 2's two func_021C2BE4 calls are one call
 * with the last two arguments set in an if/else (cross-jumped into case 0's
 * call); two separate calls come out 12 bytes long.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_020124F0(int a);
extern char **func_020124E8(int a);
extern int func_020124E4(int a);
extern int func_020120F4(int a);
extern int func_02012944(int a);
extern void *func_0201210C(void *p);
extern void *func_02043678(u8 w, u8 h, u32 tileSize, u16 heap);
extern void func_021C2BE4(char *p, char *a1, char *a2, u32 chrFile, u32 plttFile);
extern void func_021C2F84(int s, char *p, char *a1, char *a2, u32 c, u32 d);
extern void func_020437AC(void *p);
extern void func_020307B0(void *p);
extern int func_02008550(int s);
extern void func_02046BE0(int a, int b);

extern char d_021DE3E4[];
extern char d_021DE3F4[];
extern char d_021DE404[];
extern char d_021DE40C[];
extern char d_021DE418[];
extern char d_021DE428[];
extern char d_021DE43C[];
extern char d_021DE448[];

int func_021C2D68(int a, int *b)
{
    char **pp;
    int t;
    int s;
    char *p;
    u32 *q;
    u32 x;
    u32 y;

    pp = func_020124E8(func_020124F0(a));
    t = func_020124E4(a);
    s = func_02012944(func_020120F4(t));
    p = *pp;
    func_0201210C((void *)t);
    q = (u32 *)(p + 0x9c);
    switch (*b) {
    case 0:
        *(void **)(p + 0x90) = func_02043678(16, 16, 32, *(u16 *)(p + 0x10));
        func_021C2BE4(p, d_021DE3E4, d_021DE3F4, q[1], q[2]);
        (*b)++;
        break;
    case 1:
        func_020437AC(*(void **)(p + 0x90));
        func_020307B0(*(void **)(p + 0x94));
        func_020307B0(*(void **)(p + 0x98));
        func_021C2F84(s, p, d_021DE404, d_021DE40C, q[0], 0);
        (*b)++;
        break;
    case 2:
        if (q[3] == 0) {
            *b = 4;
            break;
        }
        *(void **)(p + 0x90) = func_02043678(16, 16, 32, *(u16 *)(p + 0x10));
        if (func_02008550(s) == 0) {
            x = 0;
            y = 0x16;
        } else {
            x = 1;
            y = 0x17;
        }
        func_021C2BE4(p, d_021DE418, d_021DE428, x, y);
        (*b)++;
        break;
    case 3:
        func_020437AC(*(void **)(p + 0x90));
        func_020307B0(*(void **)(p + 0x94));
        func_020307B0(*(void **)(p + 0x98));
        func_021C2F84(s, p, d_021DE43C, d_021DE448, 0, q[4]);
        (*b)++;
        break;
    case 4:
        *(int *)(p + 0x1c) = 0;
        *(int *)(p + 0x20) = 0;
        *(int *)(p + 0x24) = 0xFFD44000;
        func_02046BE0(0, 0);
        return 1;
    }
    return 0;
}
