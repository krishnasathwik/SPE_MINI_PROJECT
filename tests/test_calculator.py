import unittest
import subprocess

class TestCalculator(unittest.TestCase):
    def run_calc(self, inputs):
        """
        Run the calc executable, feed inputs, capture output.
        inputs: list of strings (simulate user input lines).
        """
        process = subprocess.Popen(
            ["./calc"],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        out, _ = process.communicate("\n".join(inputs))
        return out

    def test_sqrt(self):
        out = self.run_calc(["1", "4", "0"])  # option 1: sqrt(4), then exit
        self.assertIn("2", out)

    def test_factorial(self):
        out = self.run_calc(["2", "5", "0"])  # 5! = 120
        self.assertIn("120", out)

    def test_ln(self):
        import math
        out = self.run_calc(["3", str(math.e), "0"])
        # ln(e) ≈ 1
        self.assertIn("1", out)

    def test_power(self):
        out = self.run_calc(["4", "2", "3", "0"])  # 2^3 = 8
        self.assertIn("8", out)

if __name__ == "__main__":
    unittest.main()
