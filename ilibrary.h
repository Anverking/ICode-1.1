/*
ICode Total Library.
Notice:Direct reference to this library is not recommended.
*/

#ifndef ICODE_ILIBRARY__
#define ICODE_ILIBRARY__

#if __cplusplus < 201103L
#error "should use C++11 implementation"
#endif

/*
Junior Libraries
*/

#include "Junior/auto_ptr.h"
#include "Junior/bitblock.h"
#include "Junior/bitstream.h"
#include "Junior/chtholly_tree.h" 
#include "Junior/complex.h" 
#include "Junior/disjoint_set.h" 
#include "Junior/dancing_links.h" 
#include "Junior/FFT.h"
#include "Junior/game_theory.h"
#include "Junior/group.h" 
#include "Junior/heap.h" 
#include "Junior/huffman_tree.h" 
#include "Junior/leftist_tree.h" 
#include "Junior/linear_algebra.h"
#include "Junior/linear_base.h"
#include "Junior/linear_random.h"
#include "Junior/link_cut_tree.h" 
#include "Junior/memory_pool.h"
#include "Junior/pairing_heap.h"
#include "Junior/peak.h" 
#include "Junior/persistence_tree.h"
#include "Junior/pointer_vector.h"
#include "Junior/random_access_set.h" 
#include "Junior/RMQ.h" 
#include "Junior/scapegoat_tree.h"
#include "Junior/sequence.h"
#include "Junior/skip_list.h"
#include "Junior/sorted_queue.h"
#include "Junior/splay_tree.h"
#include "Junior/statistics.h" 
#include "Junior/thread_pool.h"
#include "Junior/treap.h"
#include "Junior/Trie.h"
#include "Junior/tuple.h" 

#ifndef __EXPORT_SENIOR // This macro is used to cancel the bulk import of the Senior library.

/*
Senior Libraries
*/

#include "Senior/arithmetic_coding.h" 
#include "Senior/B_star.h"
#include "Senior/BigInteger.h"
#include "Senior/BigDecimal.h"
#include "Senior/ex_string.h"
#include "Senior/fibonacci_heap.h"
#include "Senior/geometry.h"
#include "Senior/hash_table.h" 
#include "Senior/mathmetic.h"
#include "Senior/polynomial.h"
#include "Senior/red_black_tree.h"

#endif

#ifndef __EXPORT_TOOLS // This macro is used to cancel the bulk import of the Tools library.

/*
Tools Libraries
*/

#include "Tools/Checker.h"
#include "Tools/chrono_meter.h"
#include "Tools/File.h"
#include "Tools/log.h"
#include "Tools/optimize.h"
#include "Tools/RGBA.h"
#include "Tools/Timer.h"

#endif

#endif 
