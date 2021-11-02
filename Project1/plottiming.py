import numpy as np
import matplotlib.pyplot as plt

general_time = np.loadtxt("Textfiles/timinggen.txt")
spec_time = np.loadtxt("Textfiles/timingsp.txt")


time_N_gen_sp = []
n = np.array([10, 100, 1000, 10000])


for nn in n:
    t_gen = np.where(general_time[:, 0] == nn)
    t_sp = np.where(spec_time[:, 0] == nn)
    total_gen = len(t_gen)
    total_sp = len(t_sp)
    sum_gen = np.sum(general_time[t_gen, 1])
    sum_sp = np.sum(spec_time[t_sp, 1])
    mean_gen = sum_gen/total_gen
    mean_sp = sum_sp/total_sp
    time_N_gen_sp.append([nn, mean_gen, mean_sp])


time_N_gen_sp = np.array(time_N_gen_sp)
plt.figure()
plt.xlabel('log_10(n)')
plt.ylabel('time [s]')
plt.scatter(np.log(time_N_gen_sp[:, 0]), time_N_gen_sp[:, 1], label='General Algorithm')
plt.scatter(np.log(time_N_gen_sp[:, 0]), time_N_gen_sp[:, 2], label='Special Algorithm')
plt.legend()
plt.savefig('Images/plottime.jpg')
