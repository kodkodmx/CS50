from pyfiglet import Figlet
import sys, random

figlet = Figlet()

if len(sys.argv) == 1:
    font = random.choice(figlet.getFonts())
elif (
    len(sys.argv) < 4
    and sys.argv[2] in figlet.getFonts()
    and (sys.argv[1] == "-f" or sys.argv[1] == "--font")
):
    font = sys.argv[2]
else:
    sys.exit("Invalid usage")


inp = input("Input: ")
f = Figlet(font=font)
print(f.renderText(inp))
