/*
 * file:     unit_021DE14C_p01.c
 * unit:     yes
 * function: func_021DE14C, func_021DE184, func_021DE1F8
 * address:  0x021DE14C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021E3DF8     0x021E3DF8  data
 *   d_021E3DFC     0x021E3DFC  data
 *   d_021E3E04     0x021E3E04  data
 *   func_021829AC  0x021829AC  arm
 *   func_02182AC0  0x02182AC0  arm
 *   func_02182A2C  0x02182A2C  arm
 *   d_021E3E0C     0x021E3E0C  data
 *   d_021E3E18     0x021E3E18  data
 *   func_02182CF0  0x02182CF0  arm
 */
typedef unsigned int u32;

extern void func_021829AC(void *, void *, void *);
extern void func_02182AC0(void *, void *, void *, void *);
extern void func_02182A2C(void *, void *, void *);
extern void func_02182CF0(void *, void *, void *, void *);
int func_021DE14C(char **names, int n);
void func_021DE184(u32 ctx, u32 *arr, int n);
void func_021DE1F8(u32 ctx, u32 *arr, int n);
extern char d_021E3DF8[];
extern char d_021E3DFC[];
extern char d_021E3E04[];
extern char d_021E3E0C[];
extern char d_021E3E18[];

/*
 * ARM leaf scan over an array of string pointers: returns 7 as soon as it
 *     meets an entry with no string or an empty one, and 0 when all `n` entries
 *     carry text.  Used to reject a table of names with a hole in it.
 */
int func_021DE14C(char **names, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        char *s = names[i];

        if (s == 0 || *s == 0)
            return 7;
    }
    return 0;
}


/*
 * SDK provenance: sakeiFillSoapRequestFieldNames
 * (TwlDWC/libdwcgssake.TWL.HYB.a, sakerequestread.o), ov175.  Open the field
 * list, add one formatted element per name, then close it.
 */
void func_021DE184(u32 ctx, u32 *arr, int n)
{
    int i;

    func_021829AC(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3DFC);
    for (i = 0; i < n; i++)
        func_02182AC0(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3E04,
                      (void *)arr[i]);
    func_02182A2C(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3DFC);
}


void func_021DE1F8(u32 ctx, u32 *arr, int n)
{
    int i;

    func_021829AC(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3E0C);
    for (i = 0; i < n; i++)
        func_02182CF0(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3E18,
                      (void *)arr[i]);
    func_02182A2C(*(void **)((char *)ctx + 0x18), d_021E3DF8, d_021E3E0C);
}
