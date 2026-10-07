/*
 * file:     btl_server_p79.c
 * unit:     yes
 * function: func_021C6848, func_021C6878
 * address:  0x021C6848
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D75EC 0x021D75EC thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 */
typedef unsigned char u8;

extern void func_021D74F8(int);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int, unsigned int);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int);
void func_021C6848(u8 *p, u8 *a);
void func_021C6878(u8 *p, u8 *a, int a2);

void func_021C6848(u8 *p, u8 *a)
{
    func_021D74F8(11692);
    func_021D75EC(3, func_021D5440(a));
    func_021D70F0(p, 0x96);
    func_021D7540(11695);
}

void func_021C6878(u8 *p, u8 *a, int a2)
{
    func_021D74F8(11709);
    func_021D75EC(3, func_021D5440(a));
    func_021D70F0(p, 0x97);
    func_021D7540(11712);
}
