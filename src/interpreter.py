import os
import wave
import numpy as np

script_dir = os.path.dirname(os.path.abspath(__file__))

input_file = os.path.join(script_dir, "test")
output_file = os.path.join(script_dir, "crystal_clear_audio.wav")

raw = np.fromfile(input_file, dtype="<i4") >> 8
raw = raw.astype(np.float64)
raw -= raw.mean()

peak = np.percentile(np.abs(raw), 99)

if peak == 0:
    peak = 1

target_max = 2147483647
scaled = (raw/peak) * target_max 
scaled = np.clip(scaled, -target_max, target_max).astype(np.int32)


with wave.open(output_file, "wb") as wav_file:
    wav_file.setnchannels(1)
    wav_file.setsampwidth(4)
    wav_file.setframerate(16000)
    wav_file.writeframes(scaled.tobytes())

print(f"Exported to: {output_file} ")








