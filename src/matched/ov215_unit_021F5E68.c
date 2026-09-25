/*
 * unit:     yes
 * function: func_021F5E68, func_021F5E90
 * address:  0x021F5E68
 * packet:   pkt_021F5E68
 * region:   ov215
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B908 0x0204B908 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B98C 0x0204B98C arm
 */

struct S021F5E68
{
    char pad[0x38];
    void *slots[6];
};

extern void func_0204B908(void *, int);
extern void func_0204B92C(void *, int);
extern int func_0204B98C(void *);

void func_021F5E68(int unused, struct S021F5E68 *p)
{
    unsigned char i;
    for (i = 0; i < 6; i++)
    {
        func_0204B908(p->slots[i], 0);
        func_0204B92C(p->slots[i], 1);
    }
}

int func_021F5E90(int unused, struct S021F5E68 *p)
{
    unsigned char i;
    int r = 1;
    for (i = 0; i < 6; i++)
    {
        if (func_0204B98C(p->slots[i]) != 0)
        {
            r = 0;
            break;
        }
    }
    return r;
}
