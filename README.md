# Compile-time TRIE based string matcher (C++11)

Usage:

```
#include "cttrie.h"

...

  TRIE(str)
    ... error case
  CASE("abc")
    ... str matches abc ...
  CASE("ad")
    ... etc
  ENDTRIE;   // <- trailing semicolon!
```

* compile with optimization enabled!
* cases may return a value (see e.g. test_cttrie.cpp)
  -> return types must match! (deduced from error case)

#### => [Slides](https://smilingthax.github.io/slides/cttrie/)

Copyright (c) 2016 Tobias Hoffmann

License: http://opensource.org/licenses/MIT

