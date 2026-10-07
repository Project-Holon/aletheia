/*
 * file:     save_control_intr_p07.c
 * unit:     yes
 * function: func_021BD374, func_021BD380, func_021BD39C, func_021BD3A0
 * address:  0x021BD374
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
void func_021BD374(unsigned char *p);
int func_021BD380(unsigned char *p);
void func_021BD39C(int a0);
int func_021BD3A0(unsigned char *p);

/*
 * Unlabelled Thumb leaf in a .word run at ov088:021BD374.  The caller
 * func_021BE6E8 lives in ov204 (0x021BDA40..), which does not overlap ov088
 * (0x021B95A0..0x021BDA20), the only overlay in the window that its own
 * window does not overlap, so ov088 is the resident copy.
 */
void func_021BD374(unsigned char *p)
{
    if (p[4] != 3)
        p[6] = 0;
}

int func_021BD380(unsigned char *p){if(p[7]==1||p[4]==3)return 1;if(p[4]==2)return 1;return 0;}

/*
 * Unlabelled Thumb leaf in a .word run at ov088:021BD39C: `bx lr` (2 bytes),
 * an empty function called as a no-op by func_021BE6F8.  ov088 is the only
 * overlay in the window not overlapping the caller's ov204.
 */
void func_021BD39C(int a0)
{
}

/*
 * Unlabelled 24-byte predicate. Parent cleared this sole blocker of
 * ov204:021BE708 after SDK/ownership/unit/shard audit. Same object at p+a4
 * is passed by matched ov204:021BE6E8/021BE6F8 to ov088:021BD374/021BD39C;
 * ov204:021BEF20 initializes it from input d+c. Matched ov088:021BD3B8
 * reads the same byte fields (7 and 4), confirming the region inference.
 */
int func_021BD3A0(unsigned char *p)
{
    if (p[7] == 1)
        return 1;
    if (p[4] == 3)
        return 1;
    return 0;
}
