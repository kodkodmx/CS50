-- Keep a log of any SQL queries you execute as you solve the mystery.
.tables
.schema crime_scene_reports
SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28;
.schema intervies
SELECT transcript FROM interviews WHERE transcript LIKE '%bakery%';
.schema bakery_security_logs
SELECT name FROM people WHERE people.license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour < 11 AND hour >=10  AND minute < 25 AND minute >= 15 AND activity LIKE 'exit');
--1 personas que salieron entre 10:15 y 10:30 del estacionamiento de la panaderia

.schema atm_transactions
SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location LIKE 'Leggett Street' AND transaction_type LIKE 'withdraw';
.schema bank_accounts
SELECT DISTINCT person_id FROM bank_accounts JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number WHERE bank_accounts.account_number IN (SELECT atm_transactions.account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location LIKE 'Leggett Street' AND transaction_type LIKE 'withdraw');

.schema people

SELECT name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id WHERE people.id IN (SELECT DISTINCT person_id FROM bank_accounts JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number WHERE bank_accounts.account_number IN (SELECT atm_transactions.account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location LIKE 'Leggett Street' AND transaction_type LIKE 'withdraw'));
--2 personas que sacaron dinero esa mañana del cajero

SELECT name FROM people WHERE people.name IN (SELECT name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id WHERE people.id IN (SELECT DISTINCT person_id FROM bank_accounts JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number WHERE bank_accounts.account_number IN (SELECT atm_transactions.account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location LIKE 'Leggett Street' AND transaction_type LIKE 'withdraw'))) AND people.license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour < 11 AND hour >=10);
--personas que sus placas estuvieron en la panaderia entre 10 y 11 y que sacaron dinero esa mañana del cajero

.schema phone_calls
SELECT people.name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60);
--personas que llamaron ese dia menos de 60 segundos

SELECT phone_number FROM people WHERE name LIKE 'Bruce';
-- telefono bruce

SELECT name FROM people WHERE phone_number LIKE '(375) 555-8161';
--telefono complice


SELECT airports.id FROM airports WHERE airports.city LIKE 'Fiftyville';
SELECT full_name FROM airports WHERE airports.id = 4;
SELECT hour FROM flights WHERE day = 29 AND origin_airport_id = (SELECT airports.id FROM airports WHERE airports.city LIKE 'Fiftyville');
SELECT id, destination_airport_id FROM flights WHERE origin_airport_id = (SELECT airports.id FROM airports WHERE airports.city LIKE 'Fiftyville') AND day = 29 AND hour = (SELECT MIN(hour) FROM flights WHERE day = 29 AND origin_airport_id = (SELECT airports.id FROM airports WHERE airports.city LIKE 'Fiftyville'));
SELECT Passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE origin_airport_id = (SELECT airports.id FROM airports WHERE airports.city LIKE 'Fiftyville') AND day = 29 AND hour = (SELECT MIN(hour) FROM flights WHERE day = 29 AND origin_airport_id = (SELECT airports.id FROM airports WHERE airports.city LIKE 'Fiftyville')));
SELECT people.name FROM people WHERE passport_number IN (SELECT Passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE origin_airport_id = (SELECT airports.id FROM airports WHERE airports.city LIKE 'Fiftyville') AND day = 29 AND hour = (SELECT MIN(hour) FROM flights WHERE day = 29 AND origin_airport_id = (SELECT airports.id FROM airports WHERE airports.city LIKE 'Fiftyville'))));
--pasajeros que salieron de fiftville el dia 29 en el primer vuelo (36)



SELECT people.name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60) AND passport_number IN (SELECT Passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE origin_airport_id = (SELECT airports.id FROM airports WHERE airports.city LIKE 'Fiftyville') AND day = 29 AND hour = (SELECT MIN(hour) FROM flights WHERE day = 29 AND origin_airport_id = (SELECT airports.id FROM airports WHERE airports.city LIKE 'Fiftyville'))));
--3 llamaron y salieron


SELECT name FROM people WHERE people.license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour < 11 AND hour >=10  AND minute < 25 AND minute >= 15 AND activity LIKE 'exit') AND people.id IN (SELECT DISTINCT person_id FROM bank_accounts JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number WHERE bank_accounts.account_number IN (SELECT atm_transactions.account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location LIKE 'Leggett Street' AND transaction_type LIKE 'withdraw')) AND phone_number IN (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60) AND passport_number IN (SELECT Passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE origin_airport_id = (SELECT airports.id FROM airports WHERE airports.city LIKE 'Fiftyville') AND day = 29 AND hour = (SELECT MIN(hour) FROM flights WHERE day = 29 AND origin_airport_id = (SELECT airports.id FROM airports WHERE airports.city LIKE 'Fiftyville'))));
--ratero: 1 + 2 + 3





