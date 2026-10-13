/*
 * function: ghiPostGetContentLength
 * address:  0x021C297C
 * packet:   pkt_ov114_021C297C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlDWC/libdwcgsghttp.TWL.HYB.a(ghttppost.o).  decl_line 704.
 *
 * symbols:
 *   ghiPostGetHasFilesContentLength   0x021C26B8  arm
 *   ghiPostGetNoFilesContentLength   0x021C2620  arm
 */
extern int ghiPostGetHasFilesContentLength(void *connection);
struct GHIConnection;
extern int ghiPostGetNoFilesContentLength(struct GHIConnection *connection);

int ghiPostGetContentLength(void *connection)
{
    void *post = *(void **)((char *)connection + 0x164);

    if (!post)
        return 0;
    if (*(void **)((char *)post + 0xC))
        return ghiPostGetHasFilesContentLength(connection);
    return ghiPostGetNoFilesContentLength(connection);
}
