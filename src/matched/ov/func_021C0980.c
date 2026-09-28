/*
 * function: func_021C0980
 * address:  0x021C0980
 * packet:   pkt_021C0980
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02040804  0x02040804  arm
 *   func_02041EE4  0x02041EE4  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0204B454  0x0204B454  arm
 */

extern int func_02040804(int);
extern void func_02041EE4(int, int, int);
extern void func_0204B404(int, void *, int);
extern void func_0204B454(int, void *, int);

void func_021C0980(int a, unsigned char *p)
{
    switch (*(unsigned int *)(p + 0x70)) {
    case 0:
        break;
    case 2:
        break;
    case 1:
        if (func_02040804(7) >= 0x40) {
            func_02041EE4(7, 3, 0x40);
            *(int *)(p + 0x70) = 2;
        } else {
            func_02041EE4(7, 4, 8);
            func_02041EE4(6, 4, 8);
        }
        break;
    case 3:
        if (func_02040804(7) <= 0) {
            func_02041EE4(7, 3, 0);
            *(int *)(p + 0x70) = 0;
        } else {
            func_02041EE4(7, 5, 8);
            func_02041EE4(6, 5, 8);
        }
        break;
    }
    if (*(int *)(p + 0x5c + 4 * *(int *)(p + 0x64)) == 0)
        return;
    {
        short v[2];

        switch (*(unsigned int *)(p + 0x74)) {
        case 0:
            break;
        case 2:
            break;
        case 1:
            func_0204B454(*(int *)(p + 0x5c + 4 * *(int *)(p + 0x64)), v, 1);
            if (v[1] <= 0x70) {
                v[1] = 0x70;
                *(int *)(p + 0x74) = 2;
            } else {
                v[1] -= 8;
            }
            func_0204B404(*(int *)(p + 0x5c + 4 * *(int *)(p + 0x64)), v, 1);
            break;
        case 3:
            func_0204B454(*(int *)(p + 0x5c + 4 * *(int *)(p + 0x64)), v, 1);
            if (v[1] >= 0xb0) {
                v[1] = 0xb0;
                *(int *)(p + 0x74) = 0;
            } else {
                v[1] += 8;
            }
            func_0204B404(*(int *)(p + 0x5c + 4 * *(int *)(p + 0x64)), v, 1);
            break;
        }
    }
}
