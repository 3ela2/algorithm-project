/**
 * Simple Job Scheduling Algorithm (O(n^2))
 * This is a simple version of the algorithm, not optimized for efficiency
 */
public static int[] simpleJobSched(Item[] jobs) {

    // Get the number of jobs
    int n = jobs.length;

    // Create an array to store the job set
    int[] jobSet = new int[n];

    // Create a boolean array to represent time slots, initially all slots are free
    boolean[] slot = new boolean[n];

    // Loop through each job
    for (int i = 1; i < n; i++) {

        // Loop through each time slot from the job's deadline to the first time slot
        // This ensures that we start from the latest possible time slot
        for (int j = jobs[i].deadline; j > 0; j--) {

            // If the time slot is free, assign it to the job
            if (!slot[j]) {
                slot[j] = true;
                jobSet[j] = i;
                // Break out of the loop since we've found a time slot for the job
                break;
            }
        }
    }

    // Return the job set
    return jobSet;
}
