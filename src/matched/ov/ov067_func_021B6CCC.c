/*
 * function: MSGSEARCH_Delete
 * address:  0x021B6CCC
 * packet:   pkt_021B6CCC
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STRBUF_Delete  0x02045808  arm
 *   ENV_SetResourceSet  0x020307B0  arm
 */

struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern void ENV_SetResourceSet(void *p);

void MSGSEARCH_Delete(int *p)
{
    STRBUF_Delete((struct U16Vec *)p[0]);
    ENV_SetResourceSet(p);
}
