/*
 * file:     c_gear_p02.c
 * unit:     yes
 * function: func_021F0A38, func_021F0A68, func_021F0AA0
 * address:  0x021F0A38
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F0B88 0x021F0B88 thumb ov029
 *   func_021F0C68 0x021F0C68 thumb ov029
 *   func_021F0B7C 0x021F0B7C thumb ov029
 */
struct S021F0B7C { unsigned short f0:1; };

extern void func_021F0B88(void *p, void *q);
extern int func_021F0C68(unsigned short *);
extern void func_021F0B7C(struct S021F0B7C *);
void func_021F0A38(unsigned char *p);
int func_021F0A68(char *p);
void func_021F0AA0(char *p);

void func_021F0A38(unsigned char *p)
{
    int i, j;
    unsigned char *base;
    i = 0;
    base = p + 0x2d0;
    for (; i < 9; i++) {
        for (j = 0; j < 4; j++) func_021F0B88(base + i * 32 + j * 8, p);
    }
}

int func_021F0A68(char *p)
{
    int result, i, j;
    result = 0;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 4; j++) {
            if (func_021F0C68((unsigned short *)(p + 0x2d0 + i * 32 + j * 8))) {
                result = 1;
                break;
            }
        }
    }
    return result;
}

void func_021F0AA0(char *p)
{
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 4; j++) {
            func_021F0B7C((struct S021F0B7C *)(p + 0x2d0 + i * 32 + j * 8));
        }
    }
}
