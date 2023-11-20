--Table IntervalCo2

create table table intervalCO2
(
    intervalCO2 varchar(25),
    minCO2 numeric,
    maxCO2 numeric,
    constraint intervalCO2Pkey primary key (intervalCO2 )
)

--Table intervalDamageMillionsDollars

create table table intervalDamageMillionsDollars
(
    intervalDamageMillionsDollarsvarchar(20),
    minDamageMillionsDollars numeric,
    maxDamageMillionsDollars numeric,
    constraint intervalDamageMillionsDollarsPkey primary key (intervalDamageMillionsDollars)
)

--Table intervalDeath

create table table intervalDeath
(
    intervalDeath varchar(20),
    minDeath numeric,
    maxDeath numeric,
    constraint intervalDeathPkey primary key (intervalDeath)
)

--Table intervalDepth

create table table intervalDepth
(
    intervalDepth varchar(10),
    mindDepth numeric,
    maxDepth numeric,
    constraint intervalDepthPkey primary key (intervalDepth)
)

--Table intervalGap

create table table intervalGap
(
    intervalGap varchar(10),
    mindGap numeric,
    maxGap numeric,
    constraint intervalGapPkey primary key (intervalGap)
)

--Table intervalHorizontalDistance

create table table intervalHorizontalDistance
(
    intervalHorizontalDistance varchar(10),
    mindHorizontalDistance numeric,
    maxHorizontalDistance numeric,
    constraintintervalHorizontalDistancePkey primary key (intervalHorizontalDistance)
)

--Table intervalHousesDestroyed

create table table intervalHousesDestroyed
(
    intervalHousesDestroyed varchar(20),
    minHousesDestroyed numeric,
    maxHousesDestroyed numeric,
    constraint intervalHousesDestroyedPkey primary key (intervalHousesDestroyed)
)

--Table intervalHousesDamaged 

create table table intervalHousesDamaged
(
    intervalHousesDamaged varchar(50),
    minHousesDamaged numeric,
    maxHousesDamaged numeric,
    constraint intervalHousesDamagedPkey primary key (intervalHousesDamaged)
)

--Table intervalInjuries

create table table intervalInjuries 
(
    intervalInjuries varchar(20),
    minInjuries numeric,
    maxInjuries numeric,
    constraint intervalInjuriesPkey primary key (intervalInjuries)
)

--Table intervalMagnitude

create table table intervalMagnitude
(
    intervalMagnitude varchar(10),
    minMagnitude numeric,
    maxMagnitude numeric,
    constraint intervalMagnitudePkey primary key (intervalMagnitude)
)

--Table intervalMissing

create table table intervalMissing 
(
    intervalMissing varchar(20),
    minMissing numeric,
    maxMissing numeric,
    constraint intervalMagnitudePkey primary key (intervalMissing)
)

--Table intervalPopulationDensity

create table table intervalPopulationDensity 
(
    intervalPopulationDensity varchar(10),
    minPopulationDensity numeric,
    maxPopulationDensity numeric,
    constraint intervalPopulationDensityPkey primary key (intervalPopulationDensity)
)

--Table intervalPovertyLevel

create table table intervalPovertyLevel 
(
    intervalPovertyLevel varchar(10),
    minPovertyLevel numeric,
    maxPovertyLevel numeric,
    constraint intervalPovertyLevelPkey primary key (intervalPovertyLevel)
)

--Table intervalResidualTravelTime

create table table intervalResidualTravelTime 
(
    intervalResidualTravelTime varchar(10),
    minResidualTravelTime numeric,
    maxResidualTravelTime numeric,
    constraint ResidualTravelTimePkey primary key (intervalResidualTravelTime)
)

--Table intervalSeaLevelRise

create table table intervalSeaLevelRise 
(
    intervalSeaLevelRise varchar(10),
    minSeaLevelRise numeric,
    maxSeaLevelRise numeric,
    constraint SeaLevelRisePkey primary key (intervalSeaLevelRise)
)

--Table intervalSeismicStationNumber 

create table table intervalSeismicStationNumber 
(
    intervalSeismicStationNumber varchar(10),
    minSeismicStationNumber numeric,
    maxSeismicStationNumber numeric,
    constraint SeismicStationNumberPkey primary key (intervalSeismicStationNumber)
)

--Table intervalTemperature 

create table table intervalTemperature 
(
    intervalTemperature varchar(10),
    minTemperature numeric,
    maxTemperature numeric,
    constraint TemperaturePkey primary key (intervalTemperature)
)


