
from pathlib import Path
import matplotlib.pyplot as plt
import pandas as pd

root_dir = Path(__file__).parent.parent
out_dir = root_dir / "out"
out_file = "out.csv"
out_path = out_dir / out_file

# Load the CSV data into a DataFrame
df = pd.read_csv(out_path)

# Plot the data
plt.figure(figsize=(10, 6))
plt.plot(df['time'], df['z'])
plt.xlabel('Time (s)')
plt.ylabel('z (m)')
plt.title('z vs Time')
plt.grid(True)
plt.legend(['z'])
plt.savefig(out_dir / "out.png")