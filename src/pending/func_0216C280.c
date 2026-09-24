/*
 * function: func_0216C280
 * address:  0x0216C280
 * packet:   pkt_0216C280
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocked:  two THM_CALL sites, +0x10 -> func_02188D2C and +0x18 -> func_021BE480,
 *           have no witness in any listing: four (resp. fourteen) overlays overlap
 *           each address and none of them labels it, so resolve_relocations()
 *           wildcards the branch bytes.  Bytes are right; the site caps at MATCH.
 *           Promote when either address gets a label.
 *
 * Asks the arm9 side for the slot's descriptor, sizes it through the
 * overlay helper and copies the second word of the local into it.
 *
 * symbols:
 *   func_02011610   0x02011610  thumb
 *   func_02188D2C   0x02188D2C  thumb
 *   func_021BE480   0x021BE480  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02011610(void *, void *);
extern void *func_02188D2C(void *);
extern void *func_021BE480(void *, int, int);

void *func_0216C280(void *p)
{
    char v[12];
    void *q;

    func_02011610(*(void **)((char *)p + 0x10), v);
    q = func_021BE480(func_02188D2C(*(void **)((char *)p + 8)), 0, 0);
    *(void **)((char *)q + 4) = *(void **)(v + 4);

    return q;
}

