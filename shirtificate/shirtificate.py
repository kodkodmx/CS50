from fpdf import FPDF


class PDF(FPDF):
    def header(self):
        self.set_font("helvetica", "B", 40)
        self.cell(200, 50, "CS50 Shirtificate", align="C")
        self.ln(80)
        self.image("shirtificate.png", x=10, y=60, w=pdf.epw)
        self.set_text_color(255,255,255)
        self.set_font("helvetica", "B", 30)
        self.cell(190, 75, f"{name} took CS50", align="C")

name = input("Name: ")
pdf = PDF()
pdf.add_page()
pdf.output("shirtificate.pdf")
