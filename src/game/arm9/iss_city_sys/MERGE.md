# iss_city_sys (arm9)

2 parts (was 8; round 4 lane r4_a908 rewrote p02..p08 as typed C over one struct CitySys and merged them into p02).

- p01 (0202A994..0202AB4C) to p02 (0202AB5C): 0202AB4C and 0202AB54 are 8-byte Thumb linker veneers with no function: real boundary (unmatched code 0202AB4C..0202AB5C).
