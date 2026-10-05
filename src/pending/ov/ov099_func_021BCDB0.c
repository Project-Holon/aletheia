/*
 * function: func_021BCDB0
 * address:  0x021BCDB0
 * packet:   pkt_ov099_021BCDB0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note (2026-10-04): lane17 wave D2: 128 bytes, 9 differing bytes, same residue as ov099_func_021BCE30 (switch value/offset register swap in the 0x135C arm). The rest (0xCC branch, 021BCBBC/021BBEB4 calls) is byte-correct.
 *
 * note: 2026-10-05 (wD4 lane20): not changed; same residue as func_021BCE30 (see its note). int o instead of the enum folds the offset into a reload of the pool word (worse).
 * symbols:
 *   func_021BC06C  0x021BC06C  thumb  ov099
 *   func_020362DC  0x020362DC  arm
 *   func_021BCBBC  0x021BCBBC  thumb  ov099
 *   func_021BBEB4  0x021BBEB4  thumb  ov099
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef enum { K135c = 0x135C } Off;
extern u32 func_020362DC(void);
extern void func_021BC06C(char *p);
extern int func_021BCBBC(int a, int b, int *out);
extern void func_021BBEB4(char *p, int a, u8 b, int c);

int func_021BCDB0(char *p, int v)
{
    Off o;
    int r;
    if (func_020362DC() != 0) {
        func_021BC06C(p);
        if (*(int *)(p + 0xCC) != 0) {
            int out;
            func_021BCBBC(*(int *)(p + 0x1348), *(int *)(p + 0xCC), &out);
            func_021BBEB4(p, out, *(u8 *)(*(char **)(p + 0x248) + 0x48), 3);
            *(int *)(p + 0x1CC) = 0x78;
        } else {
            o = K135c;
            r = *(int *)(p + o);
            switch (r) {
            case 3:
                r = 0x4E;
                break;
            case 2:
                r = 0x97;
                goto store;
            case 4:
                r = 0x90;
            store:
                *(u8 *)(p + (o - 9)) = r;
                r = 0x8A;
                break;
            default:
                r = 0x72;
                break;
            }
            *(int *)(p + 0x1CC) = r;
        }
    }
    return v;
}
