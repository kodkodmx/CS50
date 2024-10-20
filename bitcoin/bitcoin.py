import sys
import requests

def main():
    try:
        bitcoins = float(sys.argv[1])
    except ValueError:
        sys.exit("Command-line argument is not a number")
    except IndexError:
        sys.exit("Missing command-line argument")

    try:
        r = requests.get(' https://api.coindesk.com/v1/bpi/currentprice.json')

    except requests.RequestException:
        sys.exit("JSON ERROR")
    else:
        rate = float(r.json()["bpi"]["USD"]["rate"].replace(',',''))
        amount = rate * bitcoins
        print(f"${amount:,.4f}")


if __name__ == "__main__":
    main()