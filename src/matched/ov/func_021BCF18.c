/*
 * function: func_021BCF18
 * address:  0x021BCF18
 * packet:   pkt_021BCF18
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD098 0x021BD098  thumb  ov208
 *   func_021BD030 0x021BD030  thumb  ov208

 * Calls func_021BD098 on +4 then func_021BD030 on the object.
 */


extern void func_021BD098(char *);
extern void func_021BD030(char *);

void func_021BCF18(char *p)
{
    func_021BD098(p + 4);
    func_021BD030(p);
}

