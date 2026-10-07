/*
 * file:     unit_0215FDA4_p08.c
 * unit:     yes
 * function: func_02160DB4, func_02160E0C
 * address:  0x02160DB4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02160D68  0x02160D68  arm  ov009
 *   d_021A1D40     0x021A1D40  data
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

int func_02160D68(unsigned char *s, int num, int size, unsigned short method);
int func_02160DB4(int a0, int a1, int a2);
int func_02160E0C(int v);
extern u16 d_021A1D40[];


/*
 * Scans the two halfword entries of a table, returning the first entry the
 * helper accepts, else zero.
 */
int func_02160DB4(int a0, int a1, int a2)
{
    u32 i;

    for (i = 0; i < 2; i++) {
        if (func_02160D68((unsigned char *)a0, a1, a2, d_021A1D40[i]))
            return d_021A1D40[i];
    }
    return 0;
}

/*
 * True when the value is 3.
 */
int func_02160E0C(int v)
{
    return v == 3;
}
