# Green Efficiency Analysis

## Measurement Methodology

All measurements were performed using the C standard library :

code :

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89`

For the baseline experiment, the deterministic loop of 100,000,000 iterations :

- 0.624391 seconds  
- 0.618204 seconds  
- 0.629887 seconds  

Stable baseline around ~0.62 seconds.

For the algorithm comparison experiment :

Naive implementation:
- 1.327742 seconds  
- 1.320375 seconds  
- 1.352283 seconds  
Average: 1.333467 seconds  

Single-pass implementation:
- 0.000041 seconds  
- 0.000041 seconds  
- 0.000080 seconds  
Average: 0.000054 seconds  

For the instrumentation experiment :

- TOTAL: 0.000577 seconds  
- BUILD_DATA: 0.000224 seconds  
- PROCESS: 0.000226 seconds  
- REDUCE: 0.000124 seconds  


---

## Observed Performance Differences

The most significant performance difference was observed in the algorithm comparison task. The naive implementation had an average runtime of 1.333467 seconds, while the single-pass implementation averaged 0.000054 seconds.

The naive version is therefore approximately:

1.333467 / 0.000054 ≈ 24,694 times slower.

In the instrumentation experiment, execution time was more evenly distributed between BUILD_DATA (0.000224 s) and PROCESS (0.000226 s), each representing roughly 39% of the total runtime. REDUCE accounted for approximately 21% of total time. The total runtime (0.000577 s) was slightly larger than the sum of sub-measurements, indicating minimal measurement overhead (~3 microseconds).

---

## Relation Between Runtime and Energy Consumption

Although energy was not directly measured, runtime is a primary driver of energy consumption on CPU-bound tasks. Assuming relatively stable CPU power usage during execution, longer execution time implies higher energy use.

In the comparison experiment, the naive implementation runs for ~1.33 seconds versus ~0.000054 seconds for the optimized version. Even if power draw were identical, the naive algorithm would consume roughly 24,000 times more CPU time, and therefore significantly more energy.

This demonstrates that algorithmic efficiency directly affects energy efficiency. Poor complexity does not only slow down software — it also increases computational waste.

---

## Limitations of the Experiment

Several limitations must be acknowledged:

1. `clock()` measures CPU time, not wall-clock time, and may not perfectly reflect real-world latency.
2. The dataset size is fixed and relatively small; behavior at larger scales may differ.
3. Energy consumption was inferred from runtime rather than directly measured with hardware tools.
4. Very short runtimes (microseconds) approach timer resolution limits, introducing variability.

---

## Practical Engineering Takeaway

Instrumentation also demonstrated that breaking down execution into phases reveals where optimization efforts should focus. In our case, processing and dataset building consume the majority of runtime.

