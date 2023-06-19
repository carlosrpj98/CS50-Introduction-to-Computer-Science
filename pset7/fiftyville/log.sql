-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Starting serching for crime scene reports in the data and locations given
SELECT description FROM crime_scene_reports
WHERE day = 28 AND month = 7 AND year = 2021
AND street = "Humphrey Street";

-- Let's check the interviews
SELECT transcript FROM interviews
WHERE day = 28 AND month = 7 AND year = 2021
AND transcript LIKE "%bakery%";

-- Checking the security logs from the courthouse
SELECT license_plate FROM courthouse_security_logs
WHERE day = 28 AND month = 7 AND year = 2021
AND hour = 10 AND minute BETWEEN 15 AND 25;

-- Looking at the ATM transactions
SELECT name, phone_number, passport_number, license_plate FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE account_number IN (SELECT account_number FROM atm_transactions
WHERE day = 28 AND month = 7 AND year = 2021
AND atm_location = "Leggett Street" AND transaction_type = "withdraw");

-- Searching for the passengers on the earliest flight
SELECT flights.id, destination_airport_id, hour, minute FROM flights
JOIN airports ON flights.origin_airport_id = airports.id
WHERE origin_airport_id = (SELECT id FROM airports
WHERE city LIKE "Fiftyville") AND day = 29
AND month = 7 AND year = 2021 ORDER BY hour, minute LIMIT 1;

-- They are going to London, the very first flight is at 8:20am
-- flight id = 36
SELECT city FROM airports
WHERE id = 4;

--Let's take a look at the passengers of on the flight wich id = 36
SELECT passport_number, seat FROM passengers
WHERE flight_id = 36 AND passport_number in
(SELECT passport_number FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE account_number IN (SELECT account_number FROM atm_transactions
WHERE day = 28 AND month = 7 AND year = 2021
AND atm_location = "Leggett Street" AND transaction_type = "withdraw"));

--Check the phone calls to find the accomplice
SELECT name, passport_number, phone_number FROM people
WHERE phone_number in (SELECT receiver FROM phone_calls
WHERE day = 28 AND month = 7 AND year = 2021
AND duration < 60 AND caller = "(367) 555-5533");
-- Danielle didn't called anyone so the main suspect is Ernest
-- and the accomplice is Berthold wich is the only one call made by Ernest
-- CODE UPDATED FROM CS50 2020 TO 2022













